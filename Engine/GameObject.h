#pragma once
#include <typeinfo>
#include <functional>
#include <vector>
#include <string>
#include "Scene.h"

class BaseComponent;
class TransformComponent;
class CollisionComponent;

class GameObject final
{
public:
	GameObject();

	~GameObject();
	GameObject(const GameObject& other) = delete;
	GameObject(GameObject&& other) = delete;
	GameObject& operator=(const GameObject& other) = delete;
	GameObject& operator=(GameObject&& other) = delete;

	BaseComponent* AddComponent(BaseComponent* component);
	void RemoveComponent(BaseComponent* component);

	void SetCollisionCallBack(std::function<void(GameObject*, bool)> collisionCallBack) { m_CollisionCallBack = collisionCallBack; }

	TransformComponent* GetTransform() const { return m_pTransform; }

	void SetTag(const std::string& tag) { m_Tag = tag; }
	const std::string& GetTag() { return m_Tag; }

	Scene* GetScene() { if (m_pScene) return m_pScene; else return nullptr; }

	void OnTrigger(GameObject* pGameObject, bool trigger) {}

#pragma region 
	///This code is completely based on Overlord engine(GP2)
	template <class T>
	bool HasComponent()
	{
		return GetComponent<T>() != nullptr;
	}

	template <class T>
	T* GetComponent()
	{
		const type_info& ti = typeid(T);
		for (auto* component : m_Components)
		{
			if (component && typeid(*component) == ti)
				return static_cast<T*>(component);
		}

		return nullptr;
	}

#pragma endregion Template Methods

protected:
	void Initialize() {}
	void Update() {}
	void Render() {}

private:
	friend class PhysicsSystem;
	friend class Scene;

	void RootInitialize();
	void RootUpdate();
	void RootRender();

	std::string m_Tag{};

	Scene* m_pScene;
	std::vector<BaseComponent*> m_Components{};
	TransformComponent* m_pTransform;
	std::function<void(GameObject*, bool)> m_CollisionCallBack;
};

