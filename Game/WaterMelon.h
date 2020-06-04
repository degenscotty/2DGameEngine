#pragma once
#include "GameObject.h"
#include "TextureComponent.h"
#include "RigidbodyComponent.h"

class WaterMelon
{
public:
	WaterMelon();
	~WaterMelon() = default;

	WaterMelon(const WaterMelon& other) = delete;
	WaterMelon(WaterMelon&& other) = delete;
	WaterMelon& operator=(const WaterMelon& other) = delete;
	WaterMelon& operator=(WaterMelon&& other) = delete;

	void Initialize();
	void Update() const;
	void Render() const;

	void SetPosition(const glm::vec2& position);
	const glm::vec2& GetPosition();

	GameObject* GetGameObject() const;
private:
	GameObject* m_pWaterMelon;
	TextureComponent* m_pTextureComponent;
	RigidbodyComponent* m_pRigidbodyComponent;
};

