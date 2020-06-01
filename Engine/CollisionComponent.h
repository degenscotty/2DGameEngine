#pragma once
#include "BaseComponent.h"
#include "PhysicsSystem.h"
#include "CollisionGroups.h"

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

	void SetOffset(const glm::vec2& offset);

	void SetCollisionGroup(CollisionGroup group);
	void SetCollisionIgnoreGroups(CollisionGroup group);
	CollisionGroup GetCollisionGroup();
	CollisionGroup GetCollisionIgnoreGroups();

	bool IsTrigger() const { return m_Trigger; } 

protected:
	void Initialize() override;
	void Update() override;
	void Render() override;

private:
	TransformComponent* m_pTransformComponent;
	PhysicsSystem* m_pPhysicsSystem;

	CollisionGroup m_Group;
	CollisionGroup m_IgnoreGroups;

	Rectf m_CollisionBox;
	bool m_IsActive;
	bool m_Trigger;
	glm::vec2 m_Offset;
};

