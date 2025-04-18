#include "UIStatus.h"
#include "ImageManager.h"
#include "Image.h"
#include "UIIcon.h"
#include "UISlider.h"
#include "UITextBox.h"
#include "CommonFunction.h"
#include "string.h"
#include "UIText.h"

using namespace UI;

void UIStatus::Release()
{
    if (icon)
    {
        icon->Release();
		delete icon;
        icon = nullptr;
    }

    if (hpBar)
    {
        hpBar->Release();
        delete hpBar;
        hpBar = nullptr;
    }

	if (expBar)
	{
		expBar->Release();
		delete expBar;
		expBar = nullptr;
	}
    if (levelTextUI)
    {
        levelTextUI->Release();
        delete levelTextUI;
        levelTextUI = nullptr;
    }
}

void UIStatus::Update()
{

	if (hpBar)
	{
		hpBar->Update();
	}
	if (expBar)
	{
		expBar->Update();
	}
}

void UIStatus::Render()
{
    if (icon)
    {
        icon->Render();
    }
	if (hpBar)
	{
		hpBar->Render();
        hpText->Render();
	}
	if (expBar)
	{
		expBar->Render();
        expText->Render();
	}
	if (levelTextUI)
	{
		levelTextUI->Render();
	}
}

void UI::UIStatus::SetLevel(int level)
{
    if (levelTextUI)
    {
        levelTextStyle.content = { L"Lv. " + to_wstring(level) };
        levelTextUI->SetTextStyle(levelTextStyle);
    }
}

void UI::UIStatus::SetHPAndExp(int hp, int maxHP, int exp, int maxExp)
{
    hpBar->SetValue(hp);
    hpBar->SetMaxValue(maxHP);
    if (hpText)
    {
        hpTextStyle.content = { to_wstring(hp) + L" / " + to_wstring(maxHP) };
        hpText->SetTextStyle(hpTextStyle);
    }
    expBar->SetValue(exp);
    expBar->SetMaxValue(maxExp);
    if (expText)
    {
        expTextStyle.content = { to_wstring(exp) + L" / " + to_wstring(maxExp) };
        expText->SetTextStyle(expTextStyle);
    }
}

void UI::UIStatus::SetStatus(StatInfo statInfo)
{
    SetLevel(statInfo.Level);
    SetHPAndExp(statInfo.HP, statInfo.MaxHP, statInfo.Exp, statInfo.MaxExp);
}

void UIStatus::ResourceInit()  
{  
   auto imageManager = ImageManager::GetInstance();  

   icon = new UIIcon();  
   icon->Init(this, FRECT{ 0, 0, 67, 68 }, { 1.f, 1.f },
       ImageData{ "status_character_ico", L"assets/interfaces/status_ico.png", true, RGB(255, 255, 255) },
       ImageData{ "status_character_bg", L"assets/interfaces/status_bg.png", true, RGB(255, 255, 255) },
       FRECT{ 10, 10 , 0, 0 });
   hpBar = new UISlider();  
   hpBar->Init(this, FRECT{ 74.25, 29.7, 355, 68 }, { 1.f, 1.f },
       ImageData{ "status_hp_bar", L"assets/interfaces/HPBar.png", true, RGB(255, 255, 255) },  
       ImageData{ "status_hp_bg", L"assets/interfaces/BarBg.png", true, RGB(255, 255, 255) }, 
       ImageData{"",L"",0,0}, FRECT{ 0,8,0,0 });
   hpBar->SetMaxValue(100);
   hpBar->SetValue(70);
   hpText = new UIText();
   hpText->Init(this, FRECT{ 200, 29.7, 355, 68 }, { 1.f, 1.f });

   expBar = new UISlider();  
   expBar->Init(this, FRECT{ 74.25, 67, 355, 97 }, { 1.f, 1.f },
       ImageData{ "status_exp_bar", L"assets/interfaces/ExpBar.png", true, RGB(255, 255, 255) },  
       ImageData{ "status_exp_bg", L"assets/interfaces/BarBg.png", true, RGB(255, 255, 255) },
       ImageData{ "",L"",0,0 }, FRECT{0,8,0,0});
   expBar->SetMaxValue(30);
   expBar->SetValue(13);
   expText = new UIText();
   expText->Init(this, FRECT{ 200, 71, 355, 68 }, { 1.f, 1.f });

   levelTextUI = new UITextBox();  
   levelTextUI->Init(this, FRECT{ 0, 74.25, 67, 97 }, {1.f, 1.f},
       ImageData{ "status_level", L"assets/interfaces/level_box.png"},
       FRECT{ 10, 0, 0, 0 });

   SetHPAndExp(70, 100, 13, 30);
   SetLevel(1);
}
