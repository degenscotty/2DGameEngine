#pragma once
#include "GameObject.h"

class Wall final
{
public:
	Wall(const glm::vec2& position, int levelNumber);
	~Wall() = default;

	Wall(const Wall& other) = delete;
	Wall(Wall&& other) = delete;
	Wall& operator=(const Wall& other) = delete;
	Wall& operator=(Wall&& other) = delete;

	void Initialize();
	void Update() const;
	void Render() const;

	GameObject* GetGameObject() const { return m_pWall; }

private:
	GameObject* m_pWall;

	glm::vec2 m_Position;
	int m_LevelNumber;
};

