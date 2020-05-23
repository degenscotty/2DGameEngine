#include "pch.h"
#include "PhysicsSystem.h"

PhysicsSystem::PhysicsSystem()
{
	
}

PhysicsSystem::~PhysicsSystem()
{
	
}

void PhysicsSystem::Update()
{
	if (m_CollisionComponents.size() > 1)
	{
		for (size_t i{ 0 }; i != m_CollisionComponents.size() - 1; ++i)
		{
			for (size_t j{ i + 1 }; j < m_CollisionComponents.size(); ++j)
			{
				if (m_CollisionComponents[i]->MinowskiDifference(m_CollisionComponents[j]->GetRect()))
				{
					// Are Colliding;
				}
			}
		}
	}
}

void PhysicsSystem::Render()
{
	
}
