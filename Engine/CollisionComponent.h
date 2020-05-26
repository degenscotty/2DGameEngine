#pragma once
#include "BaseComponent.h"
#include "PhysicsSystem.h"

class TransformComponent;

class CollisionComponent : public BaseComponent
{
public:
	CollisionComponent(float width, float height, bool trigger);
	~CollisionComponent();

	CollisionComponent(const CollisionComponent& other) = delete;
	CollisionComponent(CollisionComponent&& other) noexcept = delete;
	CollisionComponent& operator=(const CollisionComponent& other) = delete;
	CollisionComponent& operator=(CollisionComponent&& other) noexcept = delete;

	const Rectf& GetRect() const { return m_CollisionBox; }

	bool IsTrigger() const { return m_Trigger; } 

protected:
	void Initialize() override;
	void Update() override;
	void Render() override;

private:
	TransformComponent* m_pTransformComponent;
	PhysicsSystem* m_pPhysicsSystem;

	Rectf m_CollisionBox;
	bool m_IsActive;
	bool m_Trigger;
};

