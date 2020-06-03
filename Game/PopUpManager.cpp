#include "PopUpManager.h"

PopUpManager::PopUpManager()
	: m_pRenderer(Renderer::GetInstance())
	, m_pGameTime(GameTime::GetInstance())
	, m_PopUps()
{
}

PopUpManager::~PopUpManager()
{
}

void PopUpManager::Update()
{
	for (size_t i{ 0 }; i < m_PopUps.size(); ++i)
	{
		m_PopUps[i].timer += m_pGameTime->GetElapsedSec();

		m_PopUps[i].position.y += -25 * m_pGameTime->GetElapsedSec();

		if (m_PopUps[i].timer > 1.5f)
		{
			m_PopUps.erase(m_PopUps.begin() + i);
		}
	}
}

void PopUpManager::AddPopUp(const std::string& string, const glm::vec2& position, const SDL_Color& color)
{
	m_PopUps.push_back({ string, position, color, 0 });
}

void PopUpManager::Render()
{
	for (size_t i{ 0 }; i < m_PopUps.size(); ++i)
	{
		m_pRenderer->RenderText(m_PopUps[i].number, m_PopUps[i].color, "RetroGaming.ttf", 16, (int)m_PopUps[i].position.x, (int)m_PopUps[i].position.y);
	}
}
