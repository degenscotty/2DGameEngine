#pragma once
#include <glm.hpp>

#include "Singleton.h"
#include "SceneManager.h"
#include <string>

class BobblePlayer;
class PurpleWall;
class Maita;
class Bubble;
class GameObject;

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

	void AddMaita(Maita* pMaita);
	void DestroyMaita(GameObject* pGameObject);

	void AddBubble(Bubble* pBubble);
	void DestroyBubble(GameObject* pGameObject);

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
	std::vector<Maita*> m_EnemyMaita;
	std::vector<Bubble*> m_Bubbles;

	int m_LevelWidth;
	int m_LevelHeight;

	int m_EnemyCount;

	bool m_LevelInitialized;

	std::wstring m_LevelString;
};

