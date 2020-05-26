#pragma once
#include "GameObject.h"

class PurpleWall
{
public:
	PurpleWall(const glm::vec2& position);
	~PurpleWall() = default;

	PurpleWall(const PurpleWall& other) = delete;
	PurpleWall(PurpleWall&& other) = delete;
	PurpleWall& operator=(const PurpleWall& other) = delete;
	PurpleWall& operator=(PurpleWall&& other) = delete;

	void Initialize();
	void Update() const;
	void Render() const;

	GameObject* GetGameObject() const { return m_pPurpleWall; }

private:
	GameObject* m_pPurpleWall;

	glm::vec2 m_Position;
};

