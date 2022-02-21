#include "GSOpption.h"
#include "Camera.h"


GSOpption::GSOpption() : GameStateBase(StateType::STATE_OPPTION),
m_backgroundopption(nullptr), m_listButtonOpption(std::list<std::shared_ptr<GameButton>>{}), m_textOpption(nullptr)
{
}


GSOpption::~GSOpption()
{
}



void GSOpption::Init()
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto texture = ResourceManagers::GetInstance()->GetTexture("bg_main_menu.tga");
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	//background
	m_backgroundopption = std::make_shared<Sprite2D>(model, shader, texture);
	m_backgroundopption->Set2DPosition(Globals::screenWidth / 2, Globals::screenHeight / 2);
	m_backgroundopption->SetSize(Globals::screenWidth, Globals::screenHeight);

	// resume button
	texture = ResourceManagers::GetInstance()->GetTexture("btn_resume.tga");
	std::shared_ptr<GameButton> button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(Globals::screenWidth / 2, Globals::screenHeight / 2.5);
	button->SetSize(240, 80);
	button->SetOnClick([]() {
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_PLAY);
		});
	m_listButtonOpption.push_back(button);

	//back to menu button
	texture = ResourceManagers::GetInstance()->GetTexture("btn_backtomenu.tga");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(Globals::screenWidth / 2, Globals::screenHeight / 1.7);
	button->SetSize(240, 80);
	button->SetOnClick([]() {
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_MENU);
		});
	m_listButtonOpption.push_back(button);

	// game title
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("FFFFORWA.TTF");
	m_textOpption = std::make_shared< Text>(shader, font, "OPPTION", Vector4(1.0f, 0.5f, 0.0f, 1.0f), 2.3f);
	m_textOpption->Set2DPosition(Vector2(330, 140));


}

void GSOpption::Exit()
{
}


void GSOpption::Pause()
{
}

void GSOpption::Resume()
{
}


void GSOpption::HandleEvents()
{
}

void GSOpption::HandleKeyEvents(int key, bool bIsPressed)
{
}

void GSOpption::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	for (auto button : m_listButtonOpption)
	{
		if (button->HandleTouchEvents(x, y, bIsPressed))
		{
			break;
		}
	}
}

void GSOpption::HandleMouseMoveEvents(int x, int y)
{
}

void GSOpption::Update(float deltaTime)
{
	m_backgroundopption->Update(deltaTime);
	for (auto it : m_listButtonOpption)
	{
		it->Update(deltaTime);
	}
}

void GSOpption::Draw()
{
	m_backgroundopption->Draw();
	for (auto it : m_listButtonOpption)
	{
		it->Draw();
	}
	m_textOpption->Draw();
}