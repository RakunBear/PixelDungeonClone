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

        SetRect({ 0.0f, 610.0f, 398.0f, 711.0f });

        // HP 바
        auto* hpBar = new UIValueBar();
        hpBar->Init({ 75, 37, 398.5f, 68+37.13 }, {
            { D2DImageManager::GetInstance()->FindImage("status_hp_bg"), 1.0f },
            { D2DImageManager::GetInstance()->FindImage("status_hp_bar"), 1.0f }
            }, 100);
        AddChild(hpBar);
        hpBar->SetValue(70);

        // EXP 바
        auto* expBar = new UIValueBar();
        expBar->Init({ 73, 69, 396.5f, 69+32.13 }, {
            { D2DImageManager::GetInstance()->FindImage("status_exp_bg"), 1.0f },
            { D2DImageManager::GetInstance()->FindImage("status_exp_bar"), 1.0f }
            }, 30);
        AddChild(expBar);
        expBar->SetValue(13);

        // 캐릭터 아이콘
        auto* icon = new UIIcon();
        icon->Init({
            {D2DImageManager::GetInstance()->FindImage("status_character_ico")},
            {D2DImageManager::GetInstance()->FindImage("status_character_bg") },
            { 17.32,9,0,0 } }, { 0, 0, 74.25, 74.25 + 24.75 }
            );
        AddChild(icon);

        // 레벨 텍스트
        TextBoxStyle boxStyle = {
            { D2DImageManager::GetInstance()->FindImage("status_level") },
            { L"pixel", 16.0f, D2D1::ColorF(D2D1::ColorF::White), true,
                DWRITE_TEXT_ALIGNMENT_CENTER,
                DWRITE_PARAGRAPH_ALIGNMENT_CENTER
            } };
        auto* levelText = new UITextBox();
        levelText->Init(
            boxStyle,
            L"Lv. 1",
            { 0, 74, 74.25, 74.25 + 24.75 }
        );
        AddChild(levelText);
    }
};

//
// ✅ QuickSlot Toolbar (우측 하단)
//
class UIQuickSlotToolbar : public UIContainer {
public:
    void Init() {
        UIResourceSubManager::Preload_QuickSlotToolbar();

        SetRect({ 725.f, 648.f, 725.f+355.f, 648.f+71.f });

        // 아이템 슬롯 3개
        for (int i = 0; i < 3; ++i) {
            auto* slot = new UIButton();
            slot->Init({ D2DImageManager::GetInstance()->FindImage("item_quick") });
            AddChild(slot);
            slot->SetRect({ 60.f * i, 5.f, 60.f*(i+1), 71.f});
        }

        // 버튼 3개
        const char* btns[] = { "search_quick", "sleep_quick", "inven_quick" };
        const D2D_RECT_F btncoords[] = { { 180.23f, 0.0f, 234.85, 71.f }, { 234.85, 0.0f, 271.0f, 71.f }, { 289.46f, 0.0f, 355.0f, 71.f } };
        int idx = 0;
        for (auto& key : btns) {
            auto* btn = new UIButton();
            btn->Init({ D2DImageManager::GetInstance()->FindImage(key) });
            AddChild(btn);
            btn->SetRect(btncoords[idx]);
            idx += 1;
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

        SetRect({ 922.0f, 0.0f, 1080.0f, 62.32f });

        // 계단 아이콘
        auto* stairIcon = new UIIcon();
        stairIcon->Init({ D2DImageManager::GetInstance()->FindImage("stair_ico") }, { 0,0,29,31 });
        AddChild(stairIcon);

        // 층수 텍스트
        auto* stairText = new UIText();
        stairText->Init({ L"pixel", 16.0f, D2D1::ColorF::White }, L"1층", { 0,31,29,62 });
        AddChild(stairText);
        

        // 메뉴 관련 버튼
        const char* btns[] = { "guidebook_btn", "menu_btn" };
        const D2D_RECT_F btncoords[] = { { 29.f, 0, 95.68, 66.32 }, { 95.68f, 0, 159, 66.32 } };
        int idx = 0;
        for (auto& key : btns) {
            auto* btn = new UIButton();
            btn->Init({ D2DImageManager::GetInstance()->FindImage(key) });
            AddChild(btn);
            btn->SetRect(btncoords[idx]);
            idx += 1;
        }
    }
};
