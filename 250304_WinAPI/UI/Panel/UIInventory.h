#pragma once
#include "../Core/UIContainer.h"
#include "../Text/UITextBox.h"
#include "../Button/UIImageTextButton.h"
#include "../Core/UILayout.h"
#include "../VisualStyle.h"
#include "../Util/UIResourceSubManager.h"

// TODO : 지우기
#include "UI9PatchPanel.h"
#include "../Test/UITestEffectManager.h"
#include "../Util/UIHelper.h"

class UIInventory : public UIContainer {
private:
    UITextBox* titleText = nullptr;
    UIContainer* gridArea = nullptr;
    UIContainer* bottomSection = nullptr;
    
    const int numCols = 5;
    const int numRows = 5;
    const D2D1_SIZE_F slotSize = {60.f,60.f};
    const float gridSpacing = 10.0f;
    const D2D1_RECT_F padding = {20,0,21, 0 };

public:
    void Init(const D2D1_RECT_F& area = { 200, 100, 578, 569 }) {
        SetRect(area);
        UIResourceSubManager::Preload_InventoryUI();

        AddBackGround();
        AddTitleSection();
        AddGridSection();
        AddBottomSection();
    }

private:
    void AddBackGround() {
        ImageStyle imgStyle = {
            {D2DImageManager::GetInstance()->FindImage("inventory_bg")}
        };
        auto* bgImg = new UIImage();
        bgImg->Init(imgStyle, GetSizeRect());
        AddChild(bgImg);

        // // 9-Patch 스타일 정의 (공통 테두리용)
        // NinePatchStyle chromeStyle = {
        //     { D2DImageManager::GetInstance()->FindImage("chrome_tl") },
        //     { D2DImageManager::GetInstance()->FindImage("chrome_t") },
        //     { D2DImageManager::GetInstance()->FindImage("chrome_tr") },
        //     { D2DImageManager::GetInstance()->FindImage("chrome_l") },
        //      { D2DImageManager::GetInstance()->FindImage("chrome_c") },
        //      { D2DImageManager::GetInstance()->FindImage("chrome_r") },
        //     { D2DImageManager::GetInstance()->FindImage("chrome_bl") },
        //      { D2DImageManager::GetInstance()->FindImage("chrome_b") },
        //     { D2DImageManager::GetInstance()->FindImage("chrome_br") },
        //      { 6.0f, 6.0f } // 테두리 모서리 크기
        // };
        //
        // auto* inventoryBox = new UI9PatchPanel();
        // inventoryBox->Init(chromeStyle, GetSizeRect());  // 인벤토리 배경
        // AddChild(inventoryBox);
    }
    
    void AddTitleSection() {
        UIButtonStyle titleStyle = {
            {},  // 배경 없음
            { L"pixel", 18.0f, D2D1::ColorF::White, true,
              DWRITE_TEXT_ALIGNMENT_CENTER, DWRITE_PARAGRAPH_ALIGNMENT_CENTER }
        };

        titleText = new UITextBox();
        titleText->Init(titleStyle, L"배낭", { padding.left, 5, GetWidth(), 50 });
        AddChild(titleText);
    }

    void AddGridSection() {
        gridArea = new UIContainer();
        gridArea->SetRect({ 0, 50, GetWidth(), 50 + (slotSize.width + gridSpacing) * numRows } );
        gridArea->SetLayout(new UIGridLayout(numCols, gridSpacing, gridSpacing, padding.left, padding.top));
        AddChild(gridArea);

        for (int i = 0; i < numCols * numRows; ++i) {
            D2D1_RECT_F dummyRect = { 0, 0, slotSize.width, slotSize.height };
            UIInventorySlotStyle inventorySlotStyle =
                {
                    { D2DImageManager::GetInstance()->FindImage("inventory_slot"), },
                    { nullptr },
                    { L"pixel", 14.0f, D2D1::ColorF::White },
                    { L"pixel", 14.0f, D2D1::ColorF::White }
                };  // 예시 스타일
            auto* slot = UIHelper::ApplyInventorySlotStyle(*gridArea, dummyRect, inventorySlotStyle);

            slot->SetOnClick([this, i, slot]()
            {
                wstring debugString = (L"클릭 대상 [" + to_wstring(i) + L"] 클릭\n");
                UITestEffectManager::GetInstance()->AddEffect(debugString, slot->GetWorldRect());
                OutputDebugStringW(debugString.c_str());
            });
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

        AddChild(bottomSection);

        bottomSection->UpdateLayout();
    }
};
