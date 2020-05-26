#include "pch.h"
#include "PhysicsSystem.h"
#include "utils.h"
#include "CollisionComponent.h"
#include "RigidbodyComponent.h"
#include "TransformComponent.h"
#include "GameObject.h"

/// Amazing easy way of implementation basic collisions with axis-alligned bounding boxes
/// https://blog.hamaluik.ca/posts/simple-aabb-collision-using-minkowski-difference/

PhysicsSystem::PhysicsSystem()
	: m_CurrentMinowski()
	, m_CurrentPenVector()
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
					RigidbodyComponent* rigidbodyI = m_CollisionComponents[i]->GetGameObject()->GetComponent<RigidbodyComponent>();
					RigidbodyComponent* rigidbodyJ = m_CollisionComponents[j]->GetGameObject()->GetComponent<RigidbodyComponent>();

					if (rigidbodyI)
					{
						m_CurrentPenVector = CalculatePenVector();
						if (m_CurrentPenVector.y < 0)
						{
							if (rigidbodyI->GetVelocity().y < 0)
								continue;
							rigidbodyI->SetVelocityY(0);
						}
						else
						{
							if (m_CurrentPenVector.y > 0)
								continue;
						}
						m_CollisionComponents[i]->GetTransform()->Move(m_CurrentPenVector.x, m_CurrentPenVector.y);
					}
					else if (rigidbodyJ)
					{
						m_CurrentPenVector = CalculatePenVector();
						if (m_CurrentPenVector.y > 0)
						{
							if (rigidbodyJ->GetVelocity().y < 0)
								continue;
							rigidbodyJ->SetVelocityY(0);
						}
						else
						{
							if (m_CurrentPenVector.y < 0)
								continue;
						}
						m_CollisionComponents[j]->GetTransform()->Move(-m_CurrentPenVector.x, -m_CurrentPenVector.y);
					}
				}
			}
		}
	}
}

bool PhysicsSystem::CheckCollision(const Rectf& rect1, const Rectf& rect2)
{
	m_CurrentMinowski.x = rect2.x - (rect1.x + rect1.w);
	m_CurrentMinowski.y = rect2.y - (rect1.y + rect1.h);
	m_CurrentMinowski.w = rect2.w + rect1.w;
	m_CurrentMinowski.h = rect2.h + rect1.h;

	if (utils::IsPointInRect({ 0.0f, 0.0f }, { m_CurrentMinowski.x, m_CurrentMinowski.y , m_CurrentMinowski.w , m_CurrentMinowski.h }))
		return true;
	return false;
}

const glm::vec2 PhysicsSystem::CalculatePenVector() const
{
	glm::vec2 max{ m_CurrentMinowski.x + m_CurrentMinowski.w, m_CurrentMinowski.y + m_CurrentMinowski.h };
	glm::vec2 min{ m_CurrentMinowski.x, m_CurrentMinowski.y };

	glm::vec2 origin{ 0, 0, };

	float minDist = abs(origin.x - min.x);
	glm::vec2 boundsPoint{ min.x, origin.y };

	if (abs(max.x - origin.x) < minDist)
	{
		minDist = abs(max.x - origin.x);
		boundsPoint = { max.x, origin.y };
	}
	if (abs(max.y - origin.y) < minDist)
	{
		minDist = abs(max.y - origin.y);
		boundsPoint = { origin.x, max.y };
	}
	if (abs(min.y - origin.y) < minDist)
	{
		minDist = abs(min.y - origin.y);
		boundsPoint = { origin.x, min.y };
	}

	return boundsPoint;
}

