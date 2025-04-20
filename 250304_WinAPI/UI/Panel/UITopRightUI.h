#pragma once
#include "../Core/UIContainer.h"
#include "../Image/UIIcon.h"
#include "../BUtton/UIButton.h"
#include "../Text/UIText.h"
#include "../Utill/UIResourceSubManager.h"

class UITopRightUI : public UIContainer {
private:
    UIIcon* stairIcon = nullptr;
    UIText* stairText = nullptr;
    std::vector<UIButton*> menuButtons;

public:
    void Init(const D2D1_RECT_F& rect = { 922.f, 0.f, 1080.f, 62.32f }) {
        SetRect(rect);
        UIResourceSubManager::Preload_TopRightUI();

        AddStairInfo();
        AddMenuButtons();
    }

    void SetFloorText(const std::wstring& str) {
        if (stairText) stairText->SetText(str);
    }

    void SetMenuHandler(int index, std::function<void()> handler) {
        if (index >= 0 && index < menuButtons.size()) {
            menuButtons[index]->SetOnClick(handler);
        }
    }

private:
    void AddStairInfo() {
        stairIcon = new UIIcon();
        stairIcon->Init({ D2DImageManager::GetInstance()->FindImage("stair_ico") }, { 0,0,29,31 });
        AddChild(stairIcon);

        stairText = new UIText();
        stairText->Init({ L"pixel", 16.0f, D2D1::ColorF::White }, L"1층", { 0,31,29,62 });
        AddChild(stairText);
    }

    void AddMenuButtons() {
        const char* btns[] = { "guidebook_btn", "menu_btn" };
        const D2D_RECT_F coords[] = {
            { 29.f, 0, 95.68f, 66.32f },
            { 95.68f, 0, 159.0f, 66.32f }
        };

        for (int i = 0; i < 2; ++i) {
            auto* btn = new UIButton();
            btn->Init({ D2DImageManager::GetInstance()->FindImage(btns[i]) });
            btn->SetRect(coords[i]);
            AddChild(btn);
            menuButtons.push_back(btn);
        }
    }
};
