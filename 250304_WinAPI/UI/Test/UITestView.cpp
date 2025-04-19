#include "UITestView.h"
#include "UITestHeader.h"

UIContainer* uiLayer;
UIContainer* panel;

wstring ts = L"테스트용";
D2D1_RECT_F tt{ 100, -100 };
auto* tBox = new UITextBox();


void UITestView::Init()
{
	UIResourceSubManager::PreloadAll();

	uiTester = new UITestHeader();

	statusToolBar.Init();
	quickToolBar.Init();
	topRightToolBar.Init();

	uiTester->InitUI();
}

void UITestView::Release()
{
}

void UITestView::Update()
{
	statusToolBar.Update(1.0f);
	quickToolBar.Update(1.0f);
	topRightToolBar.Update(1.0f);
	if (KeyManager::GetInstance()->IsOnceKeyDown('C'))
	{
		statusToolBar.hpBar->SetValue(10);
	}

	uiTester->UpdateUI(0.1f);
}

void UITestView::Render()
{
	statusToolBar.Render(D2DImage::GetRenderTarget());
	quickToolBar.Render(D2DImage::GetRenderTarget());
	topRightToolBar.Render(D2DImage::GetRenderTarget());
	uiTester->RenderUI(D2DImage::GetRenderTarget());
}

void UITestView::Reset()
{
	Release();
	Init();
}