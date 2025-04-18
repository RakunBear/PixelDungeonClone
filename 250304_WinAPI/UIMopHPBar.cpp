#include "UIMopHPBar.h"
#include "UISlider.h"
#include "CommonFunction.h"

void UI::UIMopHPBar::Release()
{
}

void UI::UIMopHPBar::Update()
{
    hpBar->Update();
}

void UI::UIMopHPBar::Render()
{
    hpBar->Render();
}

void UI::UIMopHPBar::SetPos(float dx, float dy)
{
    UIObject::SetPos(dx, dy);
    hpBar->SetPos(0,0);
}

void UI::UIMopHPBar::SetMaxHP(int hp)
{
    hpBar->SetMaxValue(hp);
}

void UI::UIMopHPBar::SetHP(int hp)
{
    hpBar->SetValue(hp);
}

void UI::UIMopHPBar::ResourceInit()
{
    hpBar = new UISlider();
    hpBar->Init(this, { 0, 0, 0, 0 }, { 0.5f, 0.5f },
        ImageData{ "status_hp_bar2", L"assets/interfaces/HPBar.png", true, RGB(255, 255, 255) },
        ImageData{ "status_hp_bg2", L"assets/interfaces/BarBg.png", true, RGB(255, 255, 255) },
        ImageData{ "",L"",0,0 },
        { 0, 3, 0, 0 });
    hpBar->SetMaxValue(100);
    hpBar->SetValue(100);
}
