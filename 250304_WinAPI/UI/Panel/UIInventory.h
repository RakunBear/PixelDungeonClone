#pragma once
#include "../Core/UIContainer.h"
#include "../Text/UITextBox.h"
#include "../Button/UIImageTextButton.h"
#include "../Core/UILayout.h"
#include "../VisualStyle.h"
#include "../Utill/UIResourceSubManager.h"

// TODO : 지우기
#include "../Test/UITestEffectManager.h"

class UIInventory : public UIContainer {
private:
    UITextBox* titleText = nullptr;
    UIContainer* gridArea = nullptr;
    UIContainer* bottomSection = nullptr;

    std::vector<IUIInteractable*> buttons;

    const int numCols = 5;
    const int numRows = 5;
    const D2D1_SIZE_F slotSize = {60.f,60.f};
    const float gridSpacing = 10.0f;
    const D2D1_RECT_F padding = {20,0,21, 0 };

public:
    void Init(const D2D1_RECT_F& area = { 200, 100, 578, 569 }) {
        SetRect(area);
        UIResourceSubManager::Preload_InventoryUI();

        ImageStyle imgStyle = {
            {D2DImageManager::GetInstance()->FindImage("inventory_bg")}
        };
        auto* bgImg = new UIImage();
        bgImg->Init(imgStyle, GetSizeRect());
        AddChild(bgImg);

        AddTitleSection();
        AddGridSection();
        AddBottomSection();
    }

    bool HandleClick(int x, int y) const
    {
        for (auto* button : buttons) {
            if (button && button->HandleClick(x, y)) {
                return true;
            }
        }

        return false;
    }

private:
    void AddTitleSection() {
        TextBoxStyle titleStyle = {
            {},  // 배경 없음
            { L"pixel", 18.0f, D2D1::ColorF::White, true,
              DWRITE_TEXT_ALIGNMENT_CENTER, DWRITE_PARAGRAPH_ALIGNMENT_CENTER }
        };

        titleText = new UITextBox();
        titleText->Init(titleStyle, L"배낭", { 0, 0, GetWidth(), 30 });
        AddChild(titleText);
    }

    void AddGridSection() {
        gridArea = new UIContainer();
        gridArea->SetRect({ 0, 35, GetWidth(), 35 + (slotSize.width + gridSpacing) * numRows } );
        gridArea->SetLayout(new UIGridLayout(numCols, gridSpacing, gridSpacing, padding.left, padding.top));
        AddChild(gridArea);

        for (int i = 0; i < numCols * numRows; ++i) {
            auto* slot = new UIImageTextButton();
            D2D1_RECT_F dummyRect = { 0, 0, slotSize.width, slotSize.height };
            UIInventorySlotStyle inventorySlotStyle =
                {
                    { D2DImageManager::GetInstance()->FindImage("inventory_slot"), },
                    { nullptr },
                    { L"pixel", 14.0f, D2D1::ColorF::White },
                    { L"pixel", 14.0f, D2D1::ColorF::White }
                };  // 예시 스타일
            slot->InitFromStyle(inventorySlotStyle, dummyRect);
            slot->SetOnClick([this, i, slot]()
            {
                wstring debugString = (L"클릭 대상 [" + to_wstring(i) + L"] 클릭\n");
                UITestEffectManager::GetInstance()->AddEffect(debugString, slot->GetWorldRect());
                OutputDebugStringW(debugString.c_str());
            });
            gridArea->AddChild(slot);
            buttons.push_back(slot);
        }

        gridArea->UpdateLayout();
    }

    void AddBottomSection() {
        const int col = 2;
        const float padding = 10.0f;
        const float width = (GetWidth() - padding * (col + 1)) / col;
        
        bottomSection = new UIContainer();
        bottomSection->SetRect({ 0, GetHeight() - 40, GetWidth(), GetHeight() });
        bottomSection->SetLayout(new UIHorizontalLayout(padding, padding));

        auto* btn1 = new UIImageTextButton();
        btn1->Init({ 0, 0, width, 30 });
        btn1->AddText(L"정렬", { L"pixel", 14.0f, D2D1::ColorF::White }, btn1->GetSizeRect());
        btn1->SetOnClick([]() { /* 1번창 */ });

        auto* btn2 = new UIImageTextButton();
        btn2->Init({ 0, 0, width, 30 });
        btn2->AddText(L"닫기", { L"pixel", 14.0f, D2D1::ColorF::White }, btn2->GetSizeRect());
        btn2->SetOnClick([]() { /* 2번창 */ });

        bottomSection->AddChild(btn1);
        bottomSection->AddChild(btn2);
        buttons.push_back(btn1);
        buttons.push_back(btn2);

        AddChild(bottomSection);

        bottomSection->UpdateLayout();
    }
};
