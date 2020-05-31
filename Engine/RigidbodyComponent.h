#pragma once
#include "BaseComponent.h"
#include "GameTime.h"
#include "TransformComponent.h"

class RigidbodyComponent : public BaseComponent
{
public:
	RigidbodyComponent();
	~RigidbodyComponent();

	RigidbodyComponent(const RigidbodyComponent& other) = delete;
	RigidbodyComponent(RigidbodyComponent&& other) noexcept = delete;
	RigidbodyComponent& operator=(const RigidbodyComponent& other) = delete;
	RigidbodyComponent& operator=(RigidbodyComponent&& other) noexcept = delete;

	void SetVelocity(const glm::vec2& velocity);
	void SetVelocityX(float velocityX);
	void SetVelocityY(float velocityY);
	const glm::vec2& GetVelocity();

	void AddVelocity(const glm::vec2& velocity);

	void SetMoveSpeed();
	void SetGrounded(bool grounded);
	
	void SetTransform(TransformComponent* pTransformComponent);

	void SetActive(bool active) { m_Active = active; }
	
protected:
	void Initialize() override;
	void Update() override;
	void Render() override;
	
private:
	TransformComponent* m_pTransformComponent;
	GameTime* m_pGameTime;
	
	glm::vec2 m_Velocity;
	float m_Gravity;
	float m_MoveSpeed;

	bool m_Active;
};

