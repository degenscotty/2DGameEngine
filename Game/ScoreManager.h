#pragma once
#include "Singleton.h"
#include "Renderer.h"

class ScoreManager : public Singleton<ScoreManager>
{
public:
	ScoreManager();
	~ScoreManager();

	ScoreManager(const ScoreManager& other) = delete;
	ScoreManager(ScoreManager&& other) = delete;
	ScoreManager& operator=(const ScoreManager& other) = delete;
	ScoreManager& operator=(ScoreManager&& other) = delete;

	void Initialize();
	void Update();
	void Render();

	void AddScore(int score);
	int GetScore();

	void SetPosition(const glm::vec2& position);

	void Reset();

private:
	Renderer* m_pRenderer;

	glm::vec2 m_RenderPosition;
	int m_Score;
};

