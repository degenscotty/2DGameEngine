#pragma once
#include "BaseComponent.h"

class RigidbodyComponent : public BaseComponent
{
public:
	RigidbodyComponent(float width, float height);
	~RigidbodyComponent();

	RigidbodyComponent(const RigidbodyComponent& other) = delete;
	RigidbodyComponent(RigidbodyComponent&& other) noexcept = delete;
	RigidbodyComponent& operator=(const RigidbodyComponent& other) = delete;
	RigidbodyComponent& operator=(RigidbodyComponent&& other) noexcept = delete;

private:
	
};

