#include "pch.h"
#include "Scene.h"

unsigned int Scene::s_IdCounter = 0;

Scene::Scene(const std::wstring& name)
	: m_SceneName(name)
	, m_IsInitialized(false)
{
}

Scene::~Scene()
{
	for (GameObject* gameObject : m_pGameObjects)
	{
		SafeDelete(gameObject);
	}
}

void Scene::Add(GameObject* gameObject)
{
	gameObject->m_pScene = this;
	m_pGameObjects.push_back(gameObject);

	if (m_IsInitialized)
	{
		gameObject->RootInitialize();
	}
}

void Scene::Remove(GameObject* gameObject)
{
	const auto it = std::find(m_pGameObjects.begin(), m_pGameObjects.end(), gameObject);

	if (it != m_pGameObjects.end())
	{
		m_pGameObjects.erase(it);
	}
}

void Scene::RootInitialize()
{
	Initialize();

	for (size_t i{}; i < m_pGameObjects.size(); ++i)
	{
		m_pGameObjects[i]->RootInitialize();
	}

	m_IsInitialized = true;
}

void Scene::RootUpdate()
{
	Update();

	for (size_t i{}; i < m_pGameObjects.size(); ++i)
	{
		m_pGameObjects[i]->RootUpdate();
	}
}

void Scene::RootRender()
{
	for (size_t i{}; i < m_pGameObjects.size(); ++i)
	{
		m_pGameObjects[i]->RootRender();
	}

	Render();
}

const std::wstring& Scene::GetSceneName()
{
	return m_SceneName;
}


