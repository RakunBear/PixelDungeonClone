#include "UIMenueBtns.h"
#include "UIObject.h"
#include "UIText.h"
#include "UIButton.h"
#include "CommonFunction.h"

using namespace UI;

void UIMenueBtns::Release()
{
	if (stairIcon)
	{
		stairIcon->Release();
		delete stairIcon;
		stairIcon = nullptr;
	}
	if (stairTextUI)
	{
		stairTextUI->Release();
		delete stairTextUI;
		stairTextUI = nullptr;
	}
	if (guideBookBtn)
	{
		guideBookBtn->Release();
		delete guideBookBtn;
		guideBookBtn = nullptr;
	}
	if (menuBtn)
	{
		menuBtn->Release();
		delete menuBtn;
		menuBtn = nullptr;
	}
}

void UIMenueBtns::Update()
{
}

void UIMenueBtns::Render()
{
	if (stairIcon)
	{
		stairIcon->Render();
	}
	if (stairTextUI)
	{
		stairTextUI->Render();
	}
	if (guideBookBtn)
	{
		guideBookBtn->Render();
	}
	if (menuBtn)
	{
		menuBtn->Render();
	}
}

void UIMenueBtns::ResourceInit()
{
	stairIcon = new UIIcon();
	stairIcon->Init(this, { 0,5,33,29 }, { 1.0f, 1.0f },
		ImageData{ "stair_ico", L"assets/interfaces/stair_ico.png", true, RGB(255, 255, 255) });
	stairTextUI = new UIText();
	stairTextUI->Init(this, {0,40,49,56},
		"1", RGB(255, 255, 255));
	guideBookBtn = new UIButton();
	guideBookBtn->Init(this, { 7, 0, 104, 56 }, { 1.0f, 1.0f },
		ImageData{ "guidebook_btn", L"assets/interfaces/guidebook_btn.png", true, RGB(255, 255, 255) });
	menuBtn = new UIButton();
	menuBtn->Init(this, { 16, 0, 159, 56 }, { 1.0f, 1.0f },
		ImageData{ "menu_btn", L"assets/interfaces/menu_btn.png", true, RGB(255, 255, 255) });

}
