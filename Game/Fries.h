#pragma once
#include "GameObject.h"
#include "TextureComponent.h"
#include "RigidbodyComponent.h"

class Fries
{
public:
	Fries();
	~Fries() = default;

	Fries(const Fries& other) = delete;
	Fries(Fries&& other) = delete;
	Fries& operator=(const Fries& other) = delete;
	Fries& operator=(Fries&& other) = delete;

	void Initialize();
	void Update() const;
	void Render() const;

	void SetPosition(const glm::vec2& position);
	const glm::vec2& GetPosition();

	GameObject* GetGameObject() const;
private:
	GameObject* m_pFries;
	TextureComponent* m_pTextureComponent;
	RigidbodyComponent* m_pRigidbodyComponent;
};

