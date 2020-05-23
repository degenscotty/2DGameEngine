#pragma once
#include "Singleton.h"
#include "CollisionComponent.h"
#include <vector>

class PhysicsSystem : public Singleton<PhysicsSystem>
{
public:
	PhysicsSystem();
	~PhysicsSystem();

	PhysicsSystem(const PhysicsSystem& other) = delete;
	PhysicsSystem(PhysicsSystem&& other) noexcept = delete;
	PhysicsSystem& operator=(const PhysicsSystem& other) = delete;
	PhysicsSystem& operator=(PhysicsSystem&& other) noexcept = delete;

	void Update();
	void Render();

private:
	std::vector<CollisionComponent*> m_CollisionComponents;
};

