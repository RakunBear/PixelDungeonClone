#pragma once
#include "../Core/UIContainer.h"
#include "../BUtton/UIButton.h"
#include "../Utill/UIResourceSubManager.h"

class UIQuickSlotToolbar : public UIContainer {
private:
    std::vector<UIButton*> itemSlots;
    std::vector<UIButton*> actionButtons;

public:
    void Init(const D2D1_RECT_F& rect = { 725.f, 648.f, 1080.f, 719.f }) {
        SetRect(rect);
        UIResourceSubManager::Preload_QuickSlotToolbar();

        AddItemSlots();
        AddActionButtons();
    }

    void SetItemIcon(int index, D2DImage* image) {
        if (index >= 0 && index < itemSlots.size()) {
            ImageStyle style = itemSlots[index]->GetStyle();
            style.image = image;
            itemSlots[index]->SetStyle(style);
        }
    }

    void SetActionHandler(int index, std::function<void()> handler) {
        if (index >= 0 && index < actionButtons.size()) {
            actionButtons[index]->SetOnClick(handler);
        }
    }

private:
    void AddItemSlots() {
        const int slotCount = 3;
        const float slotWidth = 60.f;
        const float slotHeight = 71.f;

        for (int i = 0; i < slotCount; ++i) {
            auto* slot = new UIButton();
            slot->Init({ D2DImageManager::GetInstance()->FindImage("item_quick") });
            slot->SetRect({ slotWidth * i, 5.f, slotWidth * (i + 1), slotHeight });
            AddChild(slot);
            itemSlots.push_back(slot);
        }
    }

    void AddActionButtons() {
        const char* keys[] = { "search_quick", "sleep_quick", "inven_quick" };
        const D2D1_RECT_F coords[] = {
            { 180.23f, 0.0f, 234.85f, 71.f },
            { 234.85f, 0.0f, 271.0f, 71.f },
            { 289.46f, 0.0f, 355.0f, 71.f }
        };

        for (int i = 0; i < 3; ++i) {
            auto* btn = new UIButton();
            btn->Init({ D2DImageManager::GetInstance()->FindImage(keys[i]) });
            btn->SetRect(coords[i]);
            AddChild(btn);
            actionButtons.push_back(btn);
        }
    }
};
