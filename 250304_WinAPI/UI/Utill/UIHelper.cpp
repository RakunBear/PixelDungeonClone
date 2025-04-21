#include "UIHelper.h"

#include "../Button/UIImageTextButton.h"  // 실제 구현에 필요
#include "../UIData.h"              // UIInventorySlotData 정의
#include "../Bar/UIValueBar.h"
#include "../Text/UIText.h"               // 텍스트 적용
#include "../VisualStyle.h"
#include "StyleUtil.h"

namespace UIHelper {
    UIImageTextButton* ApplyInventorySlotStyle(UIContainerBase& target, const D2D1_RECT_F& localRect, const UIInventorySlotStyle& style,
        const std::function<void()>& onClick, bool clone) {
        // auto effectiveStyle = clone ? StyleUtil::CloneInventorySlotStyle(style) : style;

        auto& effectiveStyle = style;

        auto button = new UIImageTextButton();
        button->Init(localRect);
        target.AddChild(button);
        
        auto rect = button->GetSizeRect();
        button->AddImage(effectiveStyle.background, rect);
        button->AddImage(effectiveStyle.itemIcon, rect);
        button->AddText(L"", effectiveStyle.quantityTextStyle, rect);     // 좌상단 수량
        button->AddText(L"", effectiveStyle.enhancementTextStyle, rect);  // 우하단 강화
        button->SetOnClick(onClick);

        return button;
    }

    UIImageTextButton* ApplyIconStyle(UIContainerBase& target, const D2D1_RECT_F& localRect, const UIIconStyle& style,
        const std::function<void()>& onClick, bool clone)
    {
        // auto effectiveStyle = clone ? StyleUtil::CloneIconStyle(style) : style;
        auto& effectiveStyle =  style;
        
        auto button = new UIImageTextButton();
        button->Init(localRect);
        target.AddChild(button);
        
        auto rect = button->GetSizeRect();
        button->AddImage(effectiveStyle.bgStyle, rect);
        button->AddImage(effectiveStyle.iconStyle, rect);
        button->SetOnClick(onClick);

        return button;
    }

    UIImageTextButton* ApplyButtonStyle(UIContainerBase& target, const D2D1_RECT_F& localRect, const UIButtonStyle& style,
        const std::function<void()>& onClick, bool clone) {
        
        // auto effectiveStyle = clone ? StyleUtil::CloneButtonStyle(style) : style;
        auto& effectiveStyle =  style;

        auto button = new UIImageTextButton();
        button->Init(localRect);
        target.AddChild(button);
        
        auto rect = button->GetSizeRect();
        button->AddImage(effectiveStyle.background, rect);
        button->AddText(L"", effectiveStyle.textStyle, rect);
        button->SetOnClick(onClick);

        return button;
    }

    void SetButtonText(const UIImageTextButton& btn, const std::wstring& text, size_t index) {
        if (btn.GetTexts().size() <= index || index < 0) return;
        
        btn.GetTexts()[index]->SetText(text);
    }

    void SetButtonImage(const UIImageTextButton& btn, const ImageStyle& style, size_t index) {
        if (btn.GetImages().size() <= index || index < 0) return;
        
        btn.GetImages()[index]->SetStyle(style);
    }

    void SetInventorySlotData(const UIImageTextButton& target, const UIInventorySlotData* data) {
        if (!data) return;

        // 첫 번째 텍스트: 수량
        if (target.GetTexts().size() >= 1) {
            std::wstring qty = std::to_wstring(data->quantity) ;
            target.GetTexts()[0]->SetText(qty);
        }

        // 두 번째 텍스트: 강화 수치
        if (target.GetTexts().size() >= 2) {
            std::wstring enh = std::to_wstring(data->enhancement) ;
            target.GetTexts()[1]->SetText(enh);
        }
    }
    
    void UpdateInventorySlot(UIImageTextButton& slot, const UIInventorySlotStyle& style,
                         const UIInventorySlotData& data, const std::function<void()>& onClick) {
        const auto& images = slot.GetImages();
        const auto& texts = slot.GetTexts();

        // 배경 이미지
        if (images.size() >= 1) {
            if (style.background.image)
            {
                images[0]->SetImage(style.background.image);
            }
        }

        // 아이콘 이미지
        if (images.size() >= 2) {
            if (style.itemIcon.image) {
                images[1]->SetImage(style.itemIcon.image);
            }
        }

        // 수량 텍스트
        if (texts.size() >= 1) {
            std::wstring countStr = std::to_wstring(data.quantity);
            texts[0]->SetText(countStr);
        }

        // 강화 수치 텍스트
        if (texts.size() >= 2) {
            std::wstring enhanceStr = std::to_wstring(data.enhancement);
            texts[1]->SetText(enhanceStr);
        }

        slot.SetOnClick(onClick);
    }

}