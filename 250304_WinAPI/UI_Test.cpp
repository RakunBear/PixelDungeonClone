#include "UI_Test.h"
#include "D2DImage.h"
#include "D2DImageManager.h"
#include "CommonFunction.h"
#include "config.h"
#include "UIManager.h"
#include "UIMopHPBar.h"
UI::UIMopHPBar mopHPBar;

UI::UIManager UIManager;

HRESULT UI_TestScene::Init()
{
	SetClientRect(g_hWnd, WINSIZE_X, WINSIZE_Y);

	backGround = new D2DImage();

	UIManager.Init();
	mopHPBar.Init(nullptr, WINSIZE_X/2, WINSIZE_Y/2, 50, 10);
	mopHPBar.SetMaxHP(30);
	mopHPBar.SetHP(10);

    return S_OK;
}

void UI_TestScene::Release()
{
	if (backGround)
	{
		backGround->Release();
		delete backGround;
		backGround = nullptr;
	}
}

void UI_TestScene::Update()
{
	UIManager.Update();
	mopHPBar.Update();
	mopHPBar.SetPos(g_ptMouse.x, g_ptMouse.y);

	if (KeyManager::GetInstance()->IsOnceKeyDown('K'))
	{
		UIManager.ShowDefeat(true);
		UIManager.SetStatus(UI::StatInfo{ 100, 100, 100, 100, 100 });
		mopHPBar.SetHP(20);
	}

	if (KeyManager::GetInstance()->IsOnceKeyDown('R'))
	{
		UIManager.Reset();
		mopHPBar.SetHP(30);
	}
}

void UI_TestScene::Render()
{
	backGround->DrawRect({ 0,0 }, { WINSIZE_X, WINSIZE_Y }, 4, 1.0f);
	UIManager.Render();
	mopHPBar.Render();
}
