#pragma once
#include "GameObject.h"

class InvisibleWall
{
public:
	InvisibleWall(const glm::vec2& position);
	~InvisibleWall() = default;

	InvisibleWall(const InvisibleWall& other) = delete;
	InvisibleWall(InvisibleWall&& other) = delete;
	InvisibleWall& operator=(const InvisibleWall& other) = delete;
	InvisibleWall& operator=(InvisibleWall&& other) = delete;

	void Initialize();
	void Update() const;
	void Render() const;

	GameObject* GetGameObject() const { return m_pInvisibleWall; }

private:
	GameObject* m_pInvisibleWall;

	glm::vec2 m_Position;
};

