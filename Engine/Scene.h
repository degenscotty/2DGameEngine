#pragma once
#include "SceneManager.h"
#include "Components.h"

#include <vector>
#include <string>
#include "GameObject.h"

class Scene
{
public:
	Scene(const std::wstring& name);
	virtual ~Scene();

	void Add(GameObject* gameObject);
	void Remove(GameObject* gameObject);

	Scene(const Scene& other) = delete;
	Scene(Scene&& other) = delete;
	Scene& operator=(const Scene& other) = delete;
	Scene& operator=(Scene&& other) = delete;

	const std::wstring& GetSceneName();
	bool IsInitialized() { return m_IsInitialized; }

protected:
	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;

private:
	friend class SceneManager;

	void RootInitialize();
	void RootUpdate();
	void RootRender();

	bool m_IsInitialized;
	std::wstring m_SceneName{};
	std::vector<GameObject*> m_pGameObjects{};

	static unsigned int s_IdCounter;
};
