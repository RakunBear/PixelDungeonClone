#pragma once
#include "../Core/UIContainer.h"
#include "../BUtton/UIImageTextButton.h"
#include "../Utill/UIResourceSubManager.h"
#include "../UIButtonStyle.h"

class UIQuickSlotToolbar : public UIContainer {
private:
    std::vector<UIImageTextButton*> itemSlots;
    std::vector<UIImageTextButton*> actionButtons;

public:
    void Init(const D2D1_RECT_F& rect = { 725.f, 648.f, 1080.f, 719.f }) {
        SetRect(rect);
        UIResourceSubManager::Preload_QuickSlotToolbar();

        AddItemSlots();
        AddActionButtons();
    }

    // void SetItemIcon(int index, const & style) {
    //     if (index >= 0 && index < itemSlots.size()) {
    //         itemSlots[index]->SetStyle(style);
    //     }
    // }

    void SetActionHandler(int index, std::function<void()> handler) {
        if (index >= 0 && index < actionButtons.size()) {
            // actionButtons[index]->SetOnClick(handler);
        }
    }

private:
    void AddItemSlots() {
        const int slotCount = 3;
        const float slotWidth = 60.f;
        const float slotHeight = 71.f;

        UIIconStyle slotIconStyle =
        {
            { D2DImageManager::GetInstance()->FindImage("item_quick") }
        };
        
        for (int i = 0; i < slotCount; ++i) {
            auto* slot = new UIImageTextButton();
            slot->Init({ slotWidth * i, 5.f, slotWidth * (i + 1), slotHeight });
            itemSlots.push_back(slot);
            AddChild(slot);
            
            auto* bgImage = new UIImage();
            bgImage->Init(
                slotIconStyle.bgStyle, { 0,0, slot->GetWidth(), slot->GetHeight() }
            );
            slot->AddChild(bgImage);
            
            auto* iconImage = new UIImage();
            iconImage->Init(
                slotIconStyle.iconStyle, { 0,0, slot->GetWidth(), slot->GetHeight() }
            );
            slot->AddChild(iconImage);

        }
    }

    void AddActionButtons() {
        const char* keys[] = { "search_quick", "sleep_quick", "inven_quick" };
        const D2D1_RECT_F coords[] = {
            { 180.23f, 0.0f, 234.85f, 71.f },
            { 234.85f, 0.0f, 271.0f, 71.f },
            { 289.46f, 0.0f, 355.0f, 71.f }
        };
        const int slotCount = 3;

        for (int i = 0; i < slotCount; ++i) {
            auto* slot = new UIImageTextButton();
            slot->Init(coords[i]);
            itemSlots.push_back(slot);
            AddChild(slot);
            
            UIIconStyle slotIconStyle =
            {
                { D2DImageManager::GetInstance()->FindImage("item_quick") },
                { D2DImageManager::GetInstance()->FindImage(keys[i]) }
            };
            
            auto* bgImage = new UIImage();
            bgImage->Init(
                slotIconStyle.bgStyle, {0,0, slot->GetWidth(), slot->GetHeight()}
            );
            slot->AddChild(bgImage);
            auto* iconImage = new UIImage();
            iconImage->Init(
                slotIconStyle.iconStyle, { 0,0, slot->GetWidth(), slot->GetHeight() }
            );
            slot->AddChild(iconImage);
        }
    }
};
