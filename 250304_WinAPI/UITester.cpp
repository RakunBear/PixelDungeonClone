#include "UITester.h"
#include "D2DImageManager.h"
#include "VisualStyle.h"
#include "HPBarSet.h"
#include "UIContainer.h"
#include "UIText.h"
#include "UITextBox.h"
#include "UIResourceSubManager.h"
#include "Container_FrontUIView.h"

using namespace UI;

UIContainer* uiLayer;
UIContainer* panel;
UIStatusToolbar statusToolBar;
UIQuickSlotToolbar quickToolBar;
UITopRightUI topRightToolBar;


void UI::UITester::Init()
{
	ResourceInit();
}

void UI::UITester::Release()
{
}

void UI::UITester::Update()
{
	//uiLayer->Update(1.0f);
	//panel->Update(1.0f);

	statusToolBar.Update(1.0f);
	quickToolBar.Update(1.0f);
	topRightToolBar.Update(1.0f);
}

void UI::UITester::Render()
{
	//uiLayer->Render(D2DImage::GetRenderTarget());
	//panel->Render(D2DImage::GetRenderTarget());

	statusToolBar.Render(D2DImage::GetRenderTarget());
	quickToolBar.Render(D2DImage::GetRenderTarget());
	topRightToolBar.Render(D2DImage::GetRenderTarget());
}

void UI::UITester::Reset()
{
	Release();
	Init();
}

void UI::UITester::ResourceInit()
{
	UIResourceSubManager::PreloadAll();

	statusToolBar.Init();
	quickToolBar.Init();
	topRightToolBar.Init();

#pragma region SampleTest
	BarStyle hpStyle;
	hpStyle.background.image = D2DImageManager::GetInstance()->AddImage("hp_bg", L"assets/interfaces/BarBg.png");
	hpStyle.fill.image = D2DImageManager::GetInstance()->AddImage("hp_fill", L"assets/interfaces/HPBar.png");

	auto* playerBar = new PlayerHPBar();
	playerBar->Init(D2D1::RectF(100, 0, 0, 0), hpStyle, 100);
	playerBar->SetLayout(); // 화면 왼쪽 위 고정

	auto* monsterBar = new MonsterHPBar();
	monsterBar->Init(D2D1::RectF(400, 0, 0, 0), hpStyle, 50);
	monsterBar->SetWorldPosition({ 300.0f, 200.0f });
	monsterBar->SetBaseSize({ 60.0f, 8.0f });
	monsterBar->SetScale({ 0.4f , 1.0f});  // 줌에 따라 조정 가능

	TextStyle statStyle = {
	L"맑은 고딕", 18.0f,
	D2D1::ColorF(1, 1, 1, 1),
	false,
	DWRITE_TEXT_ALIGNMENT_CENTER,
	DWRITE_PARAGRAPH_ALIGNMENT_CENTER
	};

	auto* statText = new UIText();
	statText->Init(L"STR +5", D2D1::RectF(100, 150, 250, 180), statStyle);

	uiLayer = new UIContainer();
	uiLayer->AddComponent(playerBar);
	uiLayer->AddComponent(monsterBar);
	uiLayer->AddComponent(statText);

	panel = new UIContainer();
	panel->SetRect(D2D1::RectF(100, 100, 300, 700));
	panel->SetLayout(new UIVerticalLayout(6.0f, 10.0f));

	TextBoxStyle someStyle;
	someStyle.background.image = D2DImageManager::GetInstance()->AddImage("hp_bg", L"assets/interfaces/BarBg.png");
	someStyle.textStyle = statStyle;

	for (int i = 0; i < 5; ++i) {
		auto* box = new UITextBox();
		box->Init(someStyle, L"Item " + std::to_wstring(i), D2D1::RectF(0, 0, 180, 30)); // 크기만 주면 됨
		panel->AddComponent(box);
	}
#pragma endregion

}