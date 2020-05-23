#include "pch.h"
#include "PhysicsSystem.h"
#include "utils.h"
#include "CollisionComponent.h"

PhysicsSystem::PhysicsSystem()
{
	
}

void PhysicsSystem::AddCollisionComponent(CollisionComponent* collisionComponent)
{
	m_CollisionComponents.push_back(collisionComponent);
}

void PhysicsSystem::Update()
{
	if (m_CollisionComponents.size() > 1)
	{
		for (size_t i{ 0 }; i != m_CollisionComponents.size() - 1; ++i)
		{
			for (size_t j{ i + 1 }; j < m_CollisionComponents.size(); ++j)
			{
				if (CheckCollision(m_CollisionComponents[i]->GetRect(), m_CollisionComponents[j]->GetRect()))
				{
					CORE_INFO("FIRST OFFICIAL COLLISION!");
				}
			}
		}
	}
}

bool PhysicsSystem::CheckCollision(const Rectf& rect1, const Rectf& rect2)
{
	m_CurrentMinowski.x = rect1.x - (rect2.x + rect2.w);
	m_CurrentMinowski.y = rect1.y - (rect2.y + rect2.h);
	m_CurrentMinowski.w = rect1.w + rect2.w;
	m_CurrentMinowski.h = rect1.h + rect2.h;

	if (utils::IsPointInRect({ 0.0f, 0.0f }, { m_CurrentMinowski.x, m_CurrentMinowski.y , m_CurrentMinowski.w , m_CurrentMinowski.h }))
		return true;
	return false;
}

