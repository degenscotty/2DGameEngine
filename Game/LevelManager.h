#pragma once
#include "Singleton.h"
#include "SceneManager.h"
#include <string>

#include "BobblePlayer.h"
#include "PurpleWall.h"
#include "Maita.h"

class LevelManager : public Singleton<LevelManager>
{
public:
	LevelManager();
	~LevelManager();

	LevelManager(const LevelManager& other) = delete;
	LevelManager(LevelManager&& other) = delete;
	LevelManager& operator=(const LevelManager& other) = delete;
	LevelManager& operator=(LevelManager&& other) = delete;

	void Initialize();
	void InitializeLevel();
	void Update();
	void Render();

	BobblePlayer* GetBobblePlayer() { if (m_pBobblePlayer) return m_pBobblePlayer; return nullptr; }

	bool CheckLevel();

private:
	wchar_t GetTile(int x, int y);
	void SetTile(int x, int y, wchar_t c);

	void MergeWallColliders();

	void CountHorizontalColliders();
	void CheckVerticalMatch(const glm::vec2& startPosition, int horizontalCount);

	void ClearWalls(const glm::vec2& startPosition, int horizontalCount, int verticalCount);

	SceneManager* m_pSceneManager;
	BobblePlayer* m_pBobblePlayer;
	std::vector<PurpleWall*> m_PurpleWalls;
	std::vector<Maita*> m_EnemySnails;

	int m_LevelWidth;
	int m_LevelHeight;

	int m_EnemyCount;

	bool m_LevelInitialized;

	std::wstring m_LevelString;
};

