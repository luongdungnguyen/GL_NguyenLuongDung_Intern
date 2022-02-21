
#include "GSPlay.h"

#include "Shader.h"
#include "Texture.h"
#include "Model.h"
#include "Camera.h"
#include "Font.h"
#include "Sprite2D.h"
#include "Sprite3D.h"
#include "Text.h"
#include "GameButton.h"



GSPlay::GSPlay()
{
}


GSPlay::~GSPlay()
{
}


void GSPlay::Init()
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto texture = ResourceManagers::GetInstance()->GetTexture("bg_play1.tga");

	// background
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_background = std::make_shared<Sprite2D>(model, shader, texture);
	m_background->Set2DPosition((float)Globals::screenWidth / 2, (float)Globals::screenHeight / 2);
	m_background->SetSize(Globals::screenWidth, Globals::screenHeight);

	// button opption
	texture = ResourceManagers::GetInstance()->GetTexture("btn_opption.tga");
	std::shared_ptr<GameButton>  button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(Globals::screenWidth - 80, 40);
	button->SetSize(70,70);
	button->SetOnClick([]() {
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_OPPTION);
		});
	m_listButton.push_back(button);

	// score
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("FFFFORWA.TTF");
	m_score = std::make_shared< Text>(shader, font, "SCORE : 0", TextColor::RED, 0.8);
	m_score->Set2DPosition(Vector2(5, 40));
	//animation
	shader = ResourceManagers::GetInstance()->GetShader("Animation");
	texture = ResourceManagers::GetInstance()->GetTexture("player_idle.tga");

}

void GSPlay::Exit()
{
}


void GSPlay::Pause()
{
}

void GSPlay::Resume()
{
}


void GSPlay::HandleEvents()
{
}

void GSPlay::HandleKeyEvents(int key, bool bIsPressed)
{
}

void GSPlay::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	for (auto button : m_listButton)
	{
		if(button->HandleTouchEvents(x, y, bIsPressed))
		{
			break;
		}
	}
}

void GSPlay::HandleMouseMoveEvents(int x, int y)
{
}

void GSPlay::Update(float deltaTime)
{
	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}
}

void GSPlay::Draw()
{
	m_background->Draw();
	m_score->Draw();
	for (auto it : m_listButton)
	{
		it->Draw();
	}
}