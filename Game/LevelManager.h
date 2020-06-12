#pragma once
#include <glm.hpp>

#include "Singleton.h"
#include "SceneManager.h"
#include <string>

#include "ZenChan.h"

class BobblePlayer;
class Wall;
class Maita;
class Bubble;
class GameObject;

enum class GameMode
{
	Solo = 0,
	Versus = 1,
	Coop = 2
};

class LevelManager : public Singleton<LevelManager>
{
public:
	LevelManager();
	~LevelManager();

	LevelManager(const LevelManager& other) = delete;
	LevelManager(LevelManager&& other) = delete;
	LevelManager& operator=(const LevelManager& other) = delete;
	LevelManager& operator=(LevelManager&& other) = delete;

	void Initialize(int levelNumber, GameMode gameMode);
	void InitializeLevel();
	void Update();
	void Render();

	BobblePlayer* GetBobblePlayer() { if (m_pBobblePlayer) return m_pBobblePlayer; return nullptr; }

	void AddMaita(Maita* pMaita);
	void DestroyMaita(GameObject* pGameObject);

	void AddZenChan(ZenChan* pBubble);
	void DestroyZenChan(GameObject* pGameObject);

	void AddBubble(Bubble* pBubble);
	void DestroyBubble(GameObject* pGameObject);

	bool CheckLevel();

private:
	wchar_t GetTile(int x, int y);
	void SetTile(int x, int y, char c);

	void MergeWallColliders();

	void CountHorizontalColliders();
	void CheckVerticalMatch(const glm::vec2& startPosition, int horizontalCount);

	void ClearWalls(const glm::vec2& startPosition, int horizontalCount, int verticalCount);

	void CheckGameMode(GameMode gameMode, std::ifstream& file);
	void CheckLevelNumber(int levelNumber, std::ifstream& file);
	void SearchLevelNumber(const std::string& level, std::ifstream& file);
	void SearchGameMode(const std::string& gameMode, std::ifstream& file);

	SceneManager* m_pSceneManager;
	BobblePlayer* m_pBobblePlayer;
	std::vector<Wall*> m_Walls;
	std::vector<Maita*> m_EnemyMaita;
	std::vector<ZenChan*> m_EnemyZenChan;
	std::vector<Bubble*> m_Bubbles;

	int m_LevelWidth;
	int m_LevelHeight;

	int m_EnemyCount;

	int m_CurrentLevelNumber;

	bool m_LevelInitialized;

	std::string m_LevelString;
};

