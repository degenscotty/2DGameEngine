#pragma once
#include "Scene.h"

#include "ButtonComponent.h"

class YouWinScene final : public Scene
{
public:
	YouWinScene();
	~YouWinScene();

	YouWinScene(const YouWinScene& other) = delete;
	YouWinScene(YouWinScene&& other) = delete;
	YouWinScene& operator=(const YouWinScene& other) = delete;
	YouWinScene& operator=(YouWinScene&& other) = delete;

protected:
	void Initialize() override;
	void Update() override;
	void Render() override;

private:
	ButtonComponent* m_pBackButtonComponent;
};
