#pragma once
#include "BaseComponent.h"
#include "GameTime.h"
#include "RigidbodyComponent.h"
#include "TransformComponent.h"

class ControllerComponent : public BaseComponent
{
public:
	ControllerComponent();
	~ControllerComponent();

	ControllerComponent(const ControllerComponent& other) = delete;
	ControllerComponent(ControllerComponent&& other) noexcept = delete;
	ControllerComponent& operator=(const ControllerComponent& other) = delete;
	ControllerComponent& operator=(ControllerComponent&& other) noexcept = delete;

	void Jump();
	void MoveLeft() const;
	void MoveRight() const;
	void StopMove() const;

	void SetMoveSpeed(float moveSpeed);

protected:
	void Update() override;
	void Render() override;
	void Initialize() override;
	
private:
	TransformComponent* m_pTransformComponent;
	RigidbodyComponent* m_pRigidbodyComponent;
	GameTime* m_pGameTime;
	
	float m_MoveSpeed;
	float m_JumpSpeed;

	bool m_Jumping;
};

