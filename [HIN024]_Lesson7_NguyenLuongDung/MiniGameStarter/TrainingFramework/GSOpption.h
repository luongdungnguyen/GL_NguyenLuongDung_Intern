#pragma once
#include "../GameStates/GameStateBase.h"
#include "GameButton.h"
class Sprite2D;
class Sprite3D;
class Text;
class GameButton;

class GSOpption :
	public GameStateBase
{
public:
	GSOpption();
	~GSOpption();

	void	Init() override;
	void	Exit() override;

	void	Pause() override;
	void	Resume() override;

	void	HandleEvents() override;
	void	HandleKeyEvents(int key, bool bIsPressed) override;
	void	HandleTouchEvents(int x, int y, bool bIsPressed) override;
	void	HandleMouseMoveEvents(int x, int y) override;
	void	Update(float deltaTime) override;
	void	Draw() override;

private:
	std::shared_ptr<Sprite2D>				m_backgroundopption;
	std::list<std::shared_ptr<GameButton>>	m_listButtonOpption;
	std::shared_ptr<Text>					m_textOpption;

};


