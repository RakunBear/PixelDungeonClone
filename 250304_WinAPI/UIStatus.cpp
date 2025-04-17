#include "UIStatus.h"
#include "ImageManager.h"
#include "Image.h"
#include "UIIcon.h"
#include "UITextSlider.h"
#include "UITextBox.h"
#include "CommonFunction.h"
#include "string.h"

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
	}
	if (expBar)
	{
		expBar->Render();
	}
	if (levelTextUI)
	{
		levelTextUI->Render();
	}
}

void UI::UIStatus::SetText(const string& text)
{
	if (levelTextUI)
	{
		levelTextUI->SetText(text);
	}
}

void UI::UIStatus::SetStatus(StatInfo statInfo)
{
    hpBar->SetMaxValue(statInfo.MaxHP);
    hpBar->SetValue(statInfo.HP);
    expBar->SetMaxValue(statInfo.MaxExp);
    expBar->SetValue(statInfo.Exp);
    levelTextUI->SetText("Lv. " + to_string(statInfo.Level));
}

void UIStatus::ResourceInit()  
{  
   auto imageManager = ImageManager::GetInstance();  

   icon = new UIIcon();  
   icon->Init(this, FRECT{ 0, 0, 67, 68 }, { 1.0f, 1.0f },
       ImageData{ "status_character_ico", L"assets/interfaces/status_ico.png", true, RGB(255, 255, 255) },
       ImageData{ "status_character_bg", L"assets/interfaces/status_bg.png", true, RGB(255, 255, 255) },
       FRECT{ 3, 3 , 0, 0 });
   hpBar = new UITextSlider();  
   hpBar->Init(this, FRECT{ 30, 10, 355, 68 }, { 1.f, 1.f },
       ImageData{ "status_hp_bar", L"assets/interfaces/HPBar.png", true, RGB(255, 255, 255) },  
       ImageData{ "status_hp_bg", L"assets/interfaces/BarBg.png", true, RGB(255, 255, 255) }, 
       ImageData{"",L"",0,0}, FRECT{ 0,3,0,0 });
   hpBar->SetMaxValue(100);
   hpBar->SetValue(70);

   expBar = new UITextSlider();  
   expBar->Init(this, FRECT{ 30, 25, 355, 97 }, { 1.f, 1.f },
       ImageData{ "status_exp_bar", L"assets/interfaces/ExpBar.png", true, RGB(255, 255, 255) },  
       ImageData{ "status_exp_bg", L"assets/interfaces/BarBg.png", true, RGB(255, 255, 255) },
       ImageData{ "",L"",0,0 }, FRECT{0,3,0,0});
   expBar->SetMaxValue(30);
   expBar->SetValue(13);

   levelTextUI = new UITextBox();  
   levelTextUI->Init(this, FRECT{ 0, 30, 67, 97 }, {1.f, 1.f}, "lv. 1",
       ImageData{ "status_level", L"assets/interfaces/level_box.png"},
       FRECT{ 0, 5, 0, 0 });
}
