#include "pch.h"

#include "Application.h"
#include "Renderer.h"
#include "SceneManager.h"
#include "Renderer.h"
#include "GameTime.h"
#include "InputManager.h"
#include "ResourceManager.h"
#include "SoundManager.h"
#include "GarbageCollector.h"
#include <chrono>

Application* Application::s_Instance = nullptr;

Application::Application()
{
	if (!s_Instance)
	{
		s_Instance = this;
	}
	Initialize();
}

Application::~Application()
{
	SceneManager::DestroyInstance();
	GameTime::DestroyInstance();
	Renderer::DestroyInstance();
	InputManager::DestroyInstance();
	ResourceManager::DestroyInstance();
	GarbageCollector::DestroyInstance();
	SoundManager::DestroyInstance();
	PhysicsSystem::DestroyInstance();

	delete m_pWindow;
	m_pWindow = nullptr;
}

void Application::Initialize()
{
	m_pWindow = Window::Create();
	GameTime::GetInstance()->Initialize();
	Renderer::GetInstance()->Initialize();
	SceneManager::GetInstance()->Initialize();
	SoundManager::GetInstance();
	PhysicsSystem::GetInstance();
}

void Application::Run()
{
	GameTime* gameTime = GameTime::GetInstance();
	SceneManager* sceneManager = SceneManager::GetInstance();
	Renderer* renderer = Renderer::GetInstance();
	InputManager* input = InputManager::GetInstance();
	PhysicsSystem* physics = PhysicsSystem::GetInstance();

	gameTime->SetPreviousTime(std::chrono::high_resolution_clock::now());

	while (!input->Quit())
	{
		gameTime->UpdateCurrentTime();
		gameTime->UpdateElapsedSec();

		m_pWindow->OnUpdate();
		sceneManager->Update();

		physics->Update();

		renderer->ClearBuffer();
		sceneManager->Render();
		renderer->Render();

		gameTime->UpdatePreviousTime();
	}
}