#pragma once
#include "BaseComponent.h"
#include "Renderer.h"

class InputManager;

class ButtonComponent : public BaseComponent
{
public:
	ButtonComponent(const std::string& filepathS, const std::string& filepathNS);
	~ButtonComponent() = default;

	ButtonComponent(const ButtonComponent& other) = delete;
	ButtonComponent(ButtonComponent&& other) noexcept = delete;
	ButtonComponent& operator=(const ButtonComponent& other) = delete;
	ButtonComponent& operator=(ButtonComponent&& other) noexcept = delete;

	bool OnClick();

protected:
	void Initialize() override;
	void Update() override;
	void Render() override;

private:
	TransformComponent* m_pTransformComponent;
	InputManager* m_pInputManager;
	Renderer* m_pRenderer;
	
	std::string m_FilePathS;
	std::string m_FilePathNS;
	glm::vec4 m_Rectf;
	Texture2D* m_pButtonS;
	Texture2D* m_pButtonNS;
	bool m_Selected;
};

