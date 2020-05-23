#pragma once
#include "BaseComponent.h"
#include "GameTime.h"
#include "TextComponent.h"
#include "GameObject.h"

class FPSComponent : public BaseComponent
{
public:
	FPSComponent();
	~FPSComponent();

	FPSComponent(const FPSComponent& other) = delete;
	FPSComponent(FPSComponent&& other) noexcept = delete;
	FPSComponent& operator=(const FPSComponent& other) = delete;
	FPSComponent& operator=(FPSComponent&& other) noexcept = delete;
	
protected:
	void Initialize() override;
	void Update() override;
	void Render() override;
	
private:
	GameTime* m_pGameTime;

	TransformComponent* m_pTransformComponent;
	TextComponent* m_pTextComponent;

	unsigned int m_Counter;
	unsigned int m_Sum;
	unsigned int m_FPS;
	unsigned int m_PrevFPS;

	float m_Time;
	float m_FPSUpdateTime;
};

