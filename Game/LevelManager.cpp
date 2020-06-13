#include "LevelManager.h"

#include <typeinfo>
#include <fstream>
#include "GameObject.h"
#include "BobblePlayer1.h"
#include "BobblePlayer2.h"
#include "ZenChan.h"
#include "Maita.h"
#include "Bubble.h"
#include "BubbleMaita.h"
#include "Wall.h"
#include "Scene.h"

#include "BubbleState.h"
#include "BubbleZenChan.h"

LevelManager::LevelManager()
	: m_pGameTime(GameTime::GetInstance())
	, m_pSceneManager(SceneManager::GetInstance())
	, m_pBobblePlayer1(nullptr)
	, m_pBobblePlayer2(nullptr)
	, m_WinTimer(0.0f)
	, m_WinTime(4.0f)
	, m_EnemiesInBubbles(0)
	, m_LevelWidth(32)
	, m_LevelHeight(28)
	, m_EnemyCount(0)
	, m_CurrentLevelNumber(0)
	, m_LevelInitialized(false)
{
}

LevelManager::~LevelManager()
{
	for (auto wall : m_Walls)
	{
		delete wall;
	}
	for (auto maita : m_EnemyMaita)
	{
		delete maita;
	}
	for (auto bubble : m_Bubbles)
	{
		delete bubble;
	}
	for (auto zenChan : m_EnemyZenChan)
	{
		delete zenChan;
	}

	delete m_pBobblePlayer1;
	delete m_pBobblePlayer2;
}

void LevelManager::Initialize(int levelNumber, GameMode gameMode)
{
	std::ifstream file;

	file.open("../Resources/Levels.txt");

	CheckLevelNumber(levelNumber, file);
	CheckGameMode(gameMode, file);

	bool levelRead{ false };
	std::string currentLine;
	m_CurrentLevelNumber = levelNumber;

	while (!levelRead)
	{
		std::getline(file, currentLine);

		if (currentLine == "[End]")
		{
			levelRead = true;
			continue;
		}

		m_LevelString += currentLine;
	}

	levelRead = false;

	file.close();
}

void LevelManager::CheckLevelNumber(int levelNumber, std::ifstream& file)
{
	switch (levelNumber)
	{
	case 1:
		SearchLevelNumber("[Level 1]", file);
		break;
	case 2:
		SearchLevelNumber("[Level 2]", file);
		break;
	case 3:
		SearchLevelNumber("[Level 3]", file);
		break;
	default:
		CLIENT_TRACE("Invalid LevelNumber");
		break;
	}
}

void LevelManager::CheckGameMode(GameMode gameMode, std::ifstream& file)
{
	switch (gameMode)
	{
	case GameMode::Solo:
		SearchGameMode("[Solo]", file);
		break;
	case GameMode::Versus:
		SearchGameMode("[Versus]", file);
		break;
	case GameMode::Coop:
		SearchGameMode("[Coop]", file);
		break;
	default:
		CLIENT_TRACE("Invalid GameMode");
		break;
	}
}

void LevelManager::SearchLevelNumber(const std::string& level, std::ifstream& file)
{
	bool levelFound{ false };
	std::string currentLine{};

	while (!levelFound)
	{
		std::getline(file, currentLine);
		if (currentLine == level)
			levelFound = true;

		if (file.eof())
			CLIENT_TRACE("Invalid Levels.txt");
	}
}

void LevelManager::SearchGameMode(const std::string& gameMode, std::ifstream& file)
{
	bool gameModeFound{ false };
	std::string currentLine{};

	while (!gameModeFound)
	{
		std::getline(file, currentLine);
		if (currentLine == gameMode)
			gameModeFound = true;

		if (file.eof())
			CLIENT_TRACE("Invalid Levels.txt");
	}
}


bool LevelManager::CheckLevel()
{
	return m_LevelInitialized;
}

void LevelManager::AddMaita(Maita* pMaita)
{
	m_EnemyMaita.push_back(pMaita);
	++m_EnemyCount;
}

void LevelManager::DestroyMaita(GameObject* pGameObject)
{
	auto it = std::find_if(m_EnemyMaita.begin(), m_EnemyMaita.end(), [pGameObject](Maita* pMaita)
		{
			if (reinterpret_cast<GameObject*>(pMaita->GetGameObject()) == pGameObject)
				return true;
			return false;
		});


	delete* it;
	m_EnemyMaita.erase(it);

	--m_EnemyCount;
}

void LevelManager::AddZenChan(ZenChan* pZenChan)
{
	m_EnemyZenChan.push_back(pZenChan);
	++m_EnemyCount;
}

void LevelManager::DestroyZenChan(GameObject* pGameObject)
{
	auto it = std::find_if(m_EnemyZenChan.begin(), m_EnemyZenChan.end(), [pGameObject](ZenChan* pZenChan)
		{
			if (reinterpret_cast<GameObject*>(pZenChan->GetGameObject()) == pGameObject)
				return true;
			return false;
		});


	delete* it;
	m_EnemyZenChan.erase(it);

	--m_EnemyCount;
}

void LevelManager::AddBubble(Bubble* pBubble)
{
	m_Bubbles.push_back(pBubble);
}

void LevelManager::DestroyBubble(GameObject* pGameObject)
{
	auto it = std::find_if(m_Bubbles.begin(), m_Bubbles.end(), [pGameObject](Bubble* pBubble)
		{
			if (reinterpret_cast<GameObject*>(pBubble->GetGameObject()) == pGameObject)
				return true;
			return false;
		});

	delete* it;
	m_Bubbles.erase(it);
}

void LevelManager::InitializeLevel()
{
	for (int x = 0; x < m_LevelWidth; ++x)
	{
		for (int y = 0; y < m_LevelHeight; ++y)
		{
			wchar_t tileID = GetTile(x, y);
			switch (tileID)
			{
			case L'1':
			{
				m_pBobblePlayer1 = new BobblePlayer1();
				m_pBobblePlayer1->Initialize();
				m_pBobblePlayer1->SetPosition({ x * 16.0f, y * 16.0f });
				m_pSceneManager->GetActiveScene()->Add(m_pBobblePlayer1->GetGameObject());
			}
			break;
			case L'2':
			{
				m_pBobblePlayer2 = new BobblePlayer2();
				m_pBobblePlayer2->Initialize();
				m_pBobblePlayer2->SetPosition({ x * 16.0f, y * 16.0f });
				m_pSceneManager->GetActiveScene()->Add(m_pBobblePlayer2->GetGameObject());
			}
			break;
			case L'#':
			{
				auto* wall = new Wall({ x * 16.0f, y * 16.0f }, m_CurrentLevelNumber);
				wall->Initialize();
				m_Walls.push_back(wall);
				m_pSceneManager->GetActiveScene()->Add(wall->GetGameObject());
			}
			break;
			case L'|':
			{
				auto* wall = new Wall({ x * 16.0f, y * 16.0f }, 0);
				wall->Initialize();
				m_Walls.push_back(wall);
				m_pSceneManager->GetActiveScene()->Add(wall->GetGameObject());
			}
			break;
			case L'M':
			{
				auto* enemyMaita = new Maita();
				++m_EnemyCount;
				enemyMaita->Initialize();
				enemyMaita->SetPosition({ x * 16.0f, y * 16.0f });
				m_EnemyMaita.push_back(enemyMaita);
				m_pSceneManager->GetActiveScene()->Add(enemyMaita->GetGameObject());
			}
			break;
			case L'Z':
			{
				auto* enemyZenChan = new ZenChan();
				++m_EnemyCount;
				enemyZenChan->Initialize();
				enemyZenChan->SetPosition({ x * 16.0f, y * 16.0f });
				m_EnemyZenChan.push_back(enemyZenChan);
				m_pSceneManager->GetActiveScene()->Add(enemyZenChan->GetGameObject());
			}
			break;
			default:
				break;
			}
		}
	}

	MergeWallColliders();

	m_LevelInitialized = true;
}

void LevelManager::MergeWallColliders()
{
	CountHorizontalColliders();
}

void LevelManager::CheckVerticalMatch(const glm::vec2& startPosition, int horizontalCount)
{
	int horizontalMatchCount{ 0 };
	int verticalMatchCount{ 1 };

	if (startPosition.y != 27)
	{
		for (int y = int(startPosition.y + 1); y < m_LevelHeight; ++y)
		{
			for (int x = int(startPosition.x); x < m_LevelWidth; ++x)
			{
				wchar_t tileID = GetTile(x, y);
				switch (tileID)
				{
				case L'#':
					++horizontalMatchCount;
					if (x != 31)
						continue;
					break;
				default:
					break;
				}

				if (horizontalMatchCount == horizontalCount)
				{
					++verticalMatchCount;
					x = int(startPosition.x) - 1;
					++y;
				}
				else
				{
					for (auto purpleWall : m_Walls)
					{
						if (purpleWall->GetGameObject()->GetTransform()->GetPosition() == glm::vec2{ startPosition.x * 16, startPosition.y * 16 })
						{
							purpleWall->GetGameObject()->AddComponent(new CollisionComponent(float(horizontalCount * 16), float(verticalMatchCount * 16), false));
							ClearWalls(startPosition, horizontalCount, verticalMatchCount);
							return;
						}
					}
				}

				horizontalMatchCount = 0;
			}
			horizontalMatchCount = 0;
		}
	}
	else
	{
		for (auto purpleWall : m_Walls)
		{
			if (purpleWall->GetGameObject()->GetTransform()->GetPosition() == glm::vec2{ startPosition.x * 16, startPosition.y * 16 })
			{
				CollisionComponent* pCollisionComponent = new CollisionComponent(float(horizontalCount * 16), float(16), false);
				purpleWall->GetGameObject()->AddComponent(pCollisionComponent);
				ClearWalls(startPosition, horizontalCount, verticalMatchCount);
				return;
			}
		}
	}
}

void LevelManager::CountHorizontalColliders()
{
	bool foundCollider{ false };
	glm::vec2 horizontalStartPoint{ 0, 0 };
	int horizontalCount{ 0 };

	for (int y = 0; y < m_LevelHeight; ++y)
	{
		for (int x = 0; x < m_LevelWidth; ++x)
		{
			wchar_t tileID = GetTile(x, y);
			switch (tileID)
			{
			case L'#':
				if (horizontalCount == 0)
				{
					foundCollider = true;
					horizontalStartPoint = { x, y };
				}
				++horizontalCount;
				if (x != m_LevelWidth - 1)
					continue;
				break;
			default:
				break;
			}

			if (foundCollider)
			{
				CheckVerticalMatch(horizontalStartPoint, horizontalCount);
				foundCollider = false;
			}

			horizontalCount = 0;
		}
		horizontalCount = 0;
	}
}

void LevelManager::ClearWalls(const glm::vec2& startPosition, int horizontalCount, int verticalCount)
{
	for (int y = int(startPosition.y); y < int(startPosition.y) + verticalCount; ++y)
	{
		for (int x = int(startPosition.x); x < int(startPosition.x) + horizontalCount; ++x)
		{
			SetTile(x, y, '.');
		}
	}
}

void LevelManager::Update()
{
	for (int i{}; i < m_Bubbles.size(); ++i)
	{
		auto* pBubbleState = m_Bubbles[i]->GetCurrentState();

		auto* maitaCheck = reinterpret_cast<BubbleMaita*>(pBubbleState);
		auto* zenchanCheck = reinterpret_cast<BubbleZenChan*>(pBubbleState);

		if (maitaCheck || zenchanCheck)
			++m_EnemiesInBubbles;

		m_Bubbles[i]->Update();
	}

	if (m_EnemyCount <= 0 && m_EnemiesInBubbles <= 0)
	{
		m_WinTimer += m_pGameTime->GetElapsedSec();

		if (m_WinTimer >= m_WinTime)
		{
			GarbageCollector::GetInstance()->Destroy(m_pSceneManager->GetActiveScene());
			m_pSceneManager->SetActiveScene(L"YouWinScene");
			return;
		}
	}
	else
	{
		m_WinTimer = 0.0f;
	}

	m_EnemiesInBubbles = 0;
}

wchar_t LevelManager::GetTile(int x, int y)
{
	if (x >= 0 && x < m_LevelWidth && y >= 0 && y < m_LevelHeight)
	{
		return m_LevelString[y * m_LevelWidth + x];
	}
	else
	{
		return L' ';
	}
}

void LevelManager::SetTile(int x, int y, char c)
{
	if (x >= 0 && x < m_LevelWidth && y >= 0 && y < m_LevelHeight)
	{
		m_LevelString[y * m_LevelWidth + x] = c;
	}
}

void LevelManager::Render()
{
}
