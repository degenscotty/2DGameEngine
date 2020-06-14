#include "ScoreManager.h"


ScoreManager::ScoreManager()
	: m_pRenderer(Renderer::GetInstance())
	, m_RenderPosition({ 256, 16 })
	, m_Score(0)
{
}

ScoreManager::~ScoreManager()
{
}

void ScoreManager::Initialize()
{

}

void ScoreManager::Update()
{

}

void ScoreManager::SetPosition(const glm::vec2& position)
{
	m_RenderPosition = position;
}

void ScoreManager::AddScore(int score)
{
	m_Score += score;
}

int ScoreManager::GetScore()
{
	return m_Score;
}

void ScoreManager::Reset()
{
	m_Score = 0;
}

void ScoreManager::Render()
{
	m_pRenderer->RenderText("SCORE:", { 150, 255, 150 }, "RetroGaming.ttf", 11, int(m_RenderPosition.x - 60), int(m_RenderPosition.y));
	m_pRenderer->RenderText(std::to_string(m_Score), { 150, 255, 150 }, "RetroGaming.ttf", 20, int(m_RenderPosition.x), int(m_RenderPosition.y));
}
