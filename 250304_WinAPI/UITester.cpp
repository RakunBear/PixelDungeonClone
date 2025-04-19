#include "UITester.h"
#include "D2DImageManager.h"
#include "VisualStyle.h"
#include "HPBarSet.h"
#include "UIContainer.h"
#include "UIText.h"
#include "UITextBox.h"
#include "UIResourceSubManager.h"
#include "Container_FrontUIView.h"
#include "TestHeader.h"

using namespace UI;

UIContainer* uiLayer;
UIContainer* panel;
UIStatusToolbar statusToolBar;
UIQuickSlotToolbar quickToolBar;
UITopRightUI topRightToolBar;
wstring ts = L"테스트용";
D2D1_RECT_F tt{ 100, -100 };
auto* tBox = new UITextBox();


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
	if (KeyManager::GetInstance()->IsOnceKeyDown('C'))
	{

	}

	UpdateUI(0.1f);
}

void UI::UITester::Render()
{
	//uiLayer->Render(D2DImage::GetRenderTarget());
	//panel->Render(D2DImage::GetRenderTarget());

	statusToolBar.Render(D2DImage::GetRenderTarget());
	quickToolBar.Render(D2DImage::GetRenderTarget());
	topRightToolBar.Render(D2DImage::GetRenderTarget());
	RenderUI(D2DImage::GetRenderTarget());
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

	InitUI();
}