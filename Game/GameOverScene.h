#include "Scene.h"

#include "Button.h"
#include "InputManager.h"

class GameOverScene final : public Scene
{
public:
	GameOverScene();
	~GameOverScene();

	GameOverScene(const GameOverScene& other) = delete;
	GameOverScene(GameOverScene&& other) = delete;
	GameOverScene& operator=(const GameOverScene& other) = delete;
	GameOverScene& operator=(GameOverScene&& other) = delete;

protected:
	void Initialize() override;
	void Update() override;
	void Render() override;

private:
	InputManager* m_pInputManager;
	Button m_BackButton;
	Texture2D* m_pGameOverBackGround;
};

