#pragma once
#include "UIContainer.h"
#include "UIIcon.h"
#include "UIButton.h"
#include "UIValueBar.h"
#include "UITextBox.h"
#include "UIText.h"
#include "UIResourceSubManager.h"

//
// ✅ Status Toolbar (좌측 하단)
//
class UIStatusToolbar : public UIContainer {
public:
    void Init() {
        UIResourceSubManager::Preload_StatusToolbar();

        SetRect({ 0.0f, 610.0f, 335.0f, 720.0f });

        // 캐릭터 아이콘
        auto* icon = new UIIcon();
        icon->Init({
            {D2DImageManager::GetInstance()->FindImage("status_character_ico")},
            {D2DImageManager::GetInstance()->FindImage("status_character_bg") },
            { 10,10,0,0 }
        });
        AddComponent(icon);
        icon->SetRect({ 0, 0, 67, 68 });

        // 레벨 텍스트
        TextBoxStyle boxStyle = {
            { D2DImageManager::GetInstance()->FindImage("status_level") },
            { L"pixel", 16.0f, D2D1::ColorF::White }
        };
        auto* levelText = new UITextBox();
        levelText->Init(
            boxStyle,
            L"Lv. 1",
            { 0, 0, 0, 0 }
        );
        AddComponent(levelText);
        levelText->SetRect({ 0, 74.25, 67, 97 });

        // HP 바
        auto* hpBar = new UIValueBar();
        hpBar->Init({ 0,0,0,0 }, {
            { D2DImageManager::GetInstance()->FindImage("status_hp_bg"), 1.0f },
            { D2DImageManager::GetInstance()->FindImage("status_hp_bar"), 1.0f }
            }, 100);
        hpBar->SetValue(70);
        AddComponent(hpBar);
        hpBar->SetRect({ 74.25, 29.7, 355, 68 });

        // EXP 바
        auto* expBar = new UIValueBar();
        expBar->Init({ 0,0,0,0 }, {
            { D2DImageManager::GetInstance()->FindImage("status_exp_bg"), 1.0f },
            { D2DImageManager::GetInstance()->FindImage("status_exp_bar"), 1.0f }
            }, 30);
        expBar->SetValue(13);
        AddComponent(expBar);
        expBar->SetRect({ 74.25, 67, 355, 97 });
    }
};

//
// ✅ QuickSlot Toolbar (우측 하단)
//
class UIQuickSlotToolbar : public UIContainer {
public:
    void Init() {
        UIResourceSubManager::Preload_QuickSlotToolbar();

        SetRect({ 725.0f, 649.0f, 1080.0f, 720.0f });
        SetLayout(new UIHorizontalLayout(4.0f, 4.0f));

        // 아이템 슬롯 3개
        for (int i = 0; i < 3; ++i) {
            auto* slot = new UIButton();
            slot->Init({ D2DImageManager::GetInstance()->FindImage("item_quick") });
            AddComponent(slot);
        }

        // 버튼 3개
        const char* btns[] = { "search_quick", "sleep_quick", "inven_quick" };
        for (auto& key : btns) {
            auto* btn = new UIButton();
            btn->Init({ D2DImageManager::GetInstance()->FindImage(key) });
            AddComponent(btn);
        }
    }
};

//
// ✅ Top Right UI (우측 상단)
//
class UITopRightUI : public UIContainer {
public:
    void Init() {
        UIResourceSubManager::Preload_TopRightUI();

        SetRect({ 922.0f, 0.0f, 1080.0f, 56.0f });
        SetLayout(new UIHorizontalLayout(4.0f, 4.0f));

        // 계단 아이콘
        auto* stairIcon = new UIIcon();
        stairIcon->Init({ D2DImageManager::GetInstance()->FindImage("stair_ico") });
        AddComponent(stairIcon);

        // 층수 텍스트
        auto* stairText = new UIText();
        stairText->Init(L"1층", { 0,0,0,0 }, { L"pixel", 16.0f, D2D1::ColorF::White });
        AddComponent(stairText);

        // 메뉴 관련 버튼
        const char* btns[] = { "guidebook_btn", "menu_btn" };
        for (auto& key : btns) {
            auto* btn = new UIButton();
            btn->Init({ D2DImageManager::GetInstance()->FindImage(key) });
            AddComponent(btn);
        }
    }
};
