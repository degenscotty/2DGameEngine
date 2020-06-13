#include "pch.h"
#include "ButtonComponent.h"

#include "InputManager.h"
#include "ResourceManager.h"
#include "utils.h"

ButtonComponent::ButtonComponent(const std::string& filepathS, const std::string& filepathNS)
	: m_pTransformComponent(nullptr)
	, m_pInputManager(InputManager::GetInstance())
	, m_pRenderer(Renderer::GetInstance())
	, m_FilePathS(filepathS)
	, m_FilePathNS(filepathNS)
	, m_Rectf(0, 0, 0, 0)
	, m_pButtonS(nullptr)
	, m_pButtonNS(nullptr)
	, m_Selected(false)
{

}

void ButtonComponent::Initialize()
{
	if (m_pGameObject != nullptr)
		m_pTransformComponent = GetTransform();
	else
		CORE_ERROR("ButtonComponent::Initialize() > Cannot Initialize ButtonComponent, it is not attached to a GameObject");

	SDL_Rect dest;

	m_pButtonS = ResourceManager::GetInstance()->LoadTexture(m_FilePathS);
	m_pButtonNS = ResourceManager::GetInstance()->LoadTexture(m_FilePathNS);

	SDL_QueryTexture(m_pButtonS->GetSDLTexture(), nullptr, nullptr, &dest.w, &dest.h);

	m_Rectf.x -= (float)dest.w / 2.0f;
	m_Rectf.y -= (float)dest.h / 2.0f;
	m_Rectf.z = (float)dest.w;
	m_Rectf.w = (float)dest.h;
}

void ButtonComponent::Update()
{
	auto mousePos = m_pInputManager->GetMousePos();

	glm::vec4 rect = { int(m_pTransformComponent->GetPosition().x + m_Rectf.x) , int(m_pTransformComponent->GetPosition().y + m_Rectf.y) , m_Rectf.z, m_Rectf.w };

	if (utils::IsPointInRect(mousePos, rect))
	{
		m_Selected = true;
	}
	else m_Selected = false;
}

bool ButtonComponent::OnClick()
{
	if (m_pInputManager->IsMouseButtonPressed(MOUSE_LEFT) && m_Selected)
		return true;
	return false;
}

void ButtonComponent::Render()
{
	if (m_Selected)
	{
		m_pRenderer->RenderTexture(m_pButtonS->GetSDLTexture(), int(m_pTransformComponent->GetPosition().x + m_Rectf.x), int(m_pTransformComponent->GetPosition().y + m_Rectf.y));
	}
	else
	{
		m_pRenderer->RenderTexture(m_pButtonNS->GetSDLTexture(), int(m_pTransformComponent->GetPosition().x + m_Rectf.x), int(m_pTransformComponent->GetPosition().y + m_Rectf.y));
	}
}