#include "LevelManager.h"

#include "Scene.h"

LevelManager::LevelManager()
	: m_pSceneManager(SceneManager::GetInstance())
	, m_pBobblePlayer(nullptr)
	, m_LevelWidth(32)
	, m_LevelHeight(28)
	, m_EnemyCount(0)
	, m_LevelInitialized(false)
{
}

LevelManager::~LevelManager()
{
	for (auto purpleWall : m_PurpleWalls)
	{
		delete purpleWall;
	}
	for (auto enemySnail : m_EnemySnails)
	{
		delete enemySnail;
	}

	delete m_pBobblePlayer;
}

void LevelManager::Initialize()
{
	m_LevelString += L"................................";
	m_LevelString += L"................................";
	m_LevelString += L"................................";
	m_LevelString += L"###############..###############";
	m_LevelString += L"##............................##";
	m_LevelString += L"##............................##";
	m_LevelString += L"##............................##";
	m_LevelString += L"##............................##";
	m_LevelString += L"##............................##";
	m_LevelString += L"##............................##";
	m_LevelString += L"##.............O=.............##";
	m_LevelString += L"##.............==.............##";
	m_LevelString += L"####...##################...####";
	m_LevelString += L"##............................##";
	m_LevelString += L"##............................##";
	m_LevelString += L"##............................##";
	m_LevelString += L"##............................##";
	m_LevelString += L"####...##################...####";
	m_LevelString += L"##............................##";
	m_LevelString += L"##............................##";
	m_LevelString += L"##............................##";
	m_LevelString += L"##............................##";
	m_LevelString += L"####...##################...####";
	m_LevelString += L"##............................##";
	m_LevelString += L"##............................##";
	m_LevelString += L"##.......X=...................##";
	m_LevelString += L"##.......==...................##";
	m_LevelString += L"################################";
}

bool LevelManager::CheckLevel()
{
	return m_LevelInitialized;
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
			case L'O':
			{
				m_pBobblePlayer = new BobblePlayer();
				m_pBobblePlayer->Initialize();
				m_pBobblePlayer->SetPosition({ x * 16.0f, y * 16.0f });
				m_pSceneManager->GetActiveScene()->Add(m_pBobblePlayer->GetGameObject());
			}
			break;
			case L'#':
			{
				auto* purpleWall = new PurpleWall({ x * 16.0f, y * 16.0f });
				purpleWall->Initialize();
				m_PurpleWalls.push_back(purpleWall);
				m_pSceneManager->GetActiveScene()->Add(purpleWall->GetGameObject());
			}
			break;
			case L'X':
			{
				auto* enemyMaita = new Maita();
				++m_EnemyCount;
				enemyMaita->Initialize();
				enemyMaita->SetPosition({ x * 16.0f, y * 16.0f });
				m_EnemySnails.push_back(enemyMaita);
				m_pSceneManager->GetActiveScene()->Add(enemyMaita->GetGameObject());
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
					for (auto purpleWall : m_PurpleWalls)
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
		for (auto purpleWall : m_PurpleWalls)
		{
			if (purpleWall->GetGameObject()->GetTransform()->GetPosition() == glm::vec2{ startPosition.x * 16, startPosition.y * 16 })
			{
				purpleWall->GetGameObject()->AddComponent(new CollisionComponent(float(horizontalCount * 16), float(16), false));
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

void LevelManager::SetTile(int x, int y, wchar_t c)
{
	if (x >= 0 && x < m_LevelWidth && y >= 0 && y < m_LevelHeight)
	{
		m_LevelString[y * m_LevelWidth + x] = c;
	}
}

void LevelManager::Render()
{
}
