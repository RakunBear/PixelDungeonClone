#include "UI_Test.h"
#include "D2DImage.h"
#include "D2DImageManager.h"
#include "CommonFunction.h"
#include "config.h"
#include "UITester.h"

UI::UITester Tester;

HRESULT UI_TestScene::Init()
{
	SetClientRect(g_hWnd, WINSIZE_X, WINSIZE_Y);

	Tester.Init();
    return S_OK;
}

void UI_TestScene::Release()
{
	Tester.Release();
}

void UI_TestScene::Update()
{
	Tester.Update();
	if (KeyManager::GetInstance()->IsOnceKeyDown('K'))
	{
	}

	if (KeyManager::GetInstance()->IsOnceKeyDown('R'))
	{
	}
}

void UI_TestScene::Render()
{
	Tester.Render();
}
