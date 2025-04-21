#pragma once
#include "../Core/UIContainerBase.h"
#include "../Button/UIImageTextButton.h"
#include "../Bar/UIValueBar.h"
#include "../Text/UIText.h"
#include "../VisualStyle.h"
#include "../UIData.h"
#include "StyleUtil.h"

namespace UIHelper {
    // Inventory 전용 슬롯 스타일 적용
    void ApplyInventorySlotStyle(const std::shared_ptr<UIImageTextButton>& target, const UIInventorySlotStyle& style, bool clone = false);
    void SetInventorySlotData(const std::shared_ptr<UIImageTextButton>& target, const UIInventorySlotData* data);
    void UpdateInventorySlot(const std::shared_ptr<UIImageTextButton>& slot, const UIInventorySlotStyle& style,
                             const UIInventorySlotData& data, const std::function<void()>& callback = nullptr);
    void ApplyIconStyle(const std::shared_ptr<UIImageTextButton>& target, const UIIconStyle& style, bool clone = false);
    void ApplyButtonStyle(const std::shared_ptr<UIImageTextButton>& target, const UIButtonStyle& style, bool clone = false);
    void SetButtonText(const std::shared_ptr<UIImageTextButton>& btn, const std::wstring& text, size_t index = 0);
    void SetButtonImage(const std::shared_ptr<UIImageTextButton>& btn, const ImageStylePtr& style, size_t index = 0);

    float Clamp(float value, float minVal, float maxVal);
    
    template <typename T, typename... Args>
    T* MakeUI(Args&&... args) {
        return new T(std::forward<Args>(args)...);
    }

    template <typename T>
    void RemoveChildSafe(UIContainerBase* parent, T*& child) {
        if (parent && child) {
            parent->RemoveChild(child);
            delete child;
            child = nullptr;
        }
    }
}