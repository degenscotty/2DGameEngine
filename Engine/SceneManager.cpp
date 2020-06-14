#include "pch.h"
#include "SceneManager.h"
#include "Scene.h"
#include "GarbageCollector.h"
#include "InputManager.h"

SceneManager::SceneManager()
	: m_Scenes()
	, m_ActiveScene(nullptr)
	, m_NewActiveScene(nullptr)
	, m_IsInitialized(false)
{
}

SceneManager::~SceneManager()
{
	for (int i{ 0 }; i < m_Scenes.size(); ++i)
	{
		SafeDelete(m_Scenes[i]);
	}
}

void SceneManager::Initialize()
{
	for (int i{0}; i < m_Scenes.size(); ++i)
	{
		m_Scenes[i]->RootInitialize();
	}

	m_IsInitialized = true;
}

void SceneManager::Update()
{
	GarbageCollector::GetInstance()->RootDestroy();

	if (m_NewActiveScene)
	{
		InputManager::GetInstance()->ClearInputActions();
		m_ActiveScene = m_NewActiveScene;
		m_NewActiveScene = nullptr;

		GarbageCollector::GetInstance()->RootSceneDestroy();
	}

	if (m_ActiveScene)
	{
		m_ActiveScene->RootUpdate();
	}
}

void SceneManager::Render()
{
	if (m_ActiveScene)
		m_ActiveScene->RootRender();
}

void SceneManager::AddScene(Scene* pScene)
{
	const auto it = find(m_Scenes.begin(), m_Scenes.end(), pScene);

	if (it == m_Scenes.end())
	{
		m_Scenes.push_back(pScene);

		if (m_ActiveScene == nullptr && m_NewActiveScene == nullptr)
			m_ActiveScene = pScene;

		if (m_IsInitialized)
			pScene->RootInitialize();
	}
}

void SceneManager::RemoveScene(Scene* pScene)
{
	const auto it = find(m_Scenes.begin(), m_Scenes.end(), pScene);

	if (it != m_Scenes.end())
	{
		m_Scenes.erase(it);
	}
}

void SceneManager::SetActiveScene(const std::wstring sceneName)
{
	const auto it = find_if(m_Scenes.begin(), m_Scenes.end(), [sceneName](Scene* scene)
	{
		return wcscmp(scene->m_SceneName.c_str(), sceneName.c_str()) == 0;
	});

	if (it != m_Scenes.end())
	{
		m_NewActiveScene = *it;
	}
}
