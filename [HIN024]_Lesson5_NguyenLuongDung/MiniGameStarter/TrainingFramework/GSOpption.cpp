//#include "GSOpption.h"
//#include "Camera.h"
//
//GSOpption::GSOpption() : GameStateBase(StateType::STATE_OPPTION),
//m_background(nullptr), m_listButton(std::list<std::shared_ptr<GameButton>>{}), m_textGameName(nullptr)
//{
//}
//
//
//GSOpption::~GSOpption()
//{
//}
//
//
//
//void GSOpption::Init()
//{
//	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
//
//	// play button
//	texture = ResourceManagers::GetInstance()->GetTexture("btn_play.tga");
//	std::shared_ptr<GameButton> button = std::make_shared<GameButton>(model, shader, texture);
//	button->Set2DPosition(Globals::screenWidth / 2, Globals::screenHeight / 2);
//	button->SetSize(150, 150);
//	button->SetOnClick([]() {
//		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_PLAY);
//		});
//	m_listButton.push_back(button);
//
//	// exit button
//	texture = ResourceManagers::GetInstance()->GetTexture("btn_close.tga");
//	button = std::make_shared<GameButton>(model, shader, texture);
//	button->Set2DPosition(Globals::screenWidth - 50, 50);
//	button->SetSize(50, 50);
//	button->SetOnClick([]() {
//		exit(0);
//		});
//	m_listButton.push_back(button);
//
//}
//
//void GSOpption::Exit()
//{
//}
//
//
//void GSOpption::Pause()
//{
//}
//
//void GSOpption::Resume()
//{
//}
//
//
//void GSOpption::HandleEvents()
//{
//}
//
//void GSOpption::HandleKeyEvents(int key, bool bIsPressed)
//{
//}
//
//void GSOpption::HandleTouchEvents(int x, int y, bool bIsPressed)
//{
//	for (auto button : m_listButton)
//	{
//		if (button->HandleTouchEvents(x, y, bIsPressed))
//		{
//			break;
//		}
//	}
//}
//
//void GSOpption::HandleMouseMoveEvents(int x, int y)
//{
//}
//
//void GSOpption::Update(float deltaTime)
//{
//	m_background->Update(deltaTime);
//	for (auto it : m_listButton)
//	{
//		it->Update(deltaTime);
//	}
//}
//
//void GSOpption::Draw()
//{
//	m_background->Draw();
//	for (auto it : m_listButton)
//	{
//		it->Draw();
//	}
//	m_textGameName->Draw();
//}
