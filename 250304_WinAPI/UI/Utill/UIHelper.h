#pragma once
#include "../Core/UIContainerBase.h"
#include "../Button/UIImageTextButton.h"
#include "../Bar/UIValueBar.h"
#include "../Text/UIText.h"
#include "../VisualStyle.h"
#include "../UIData.h"

namespace UIHelper {
    // Inventory 전용 슬롯 스타일 적용
    void ApplyInventorySlotStyle(UIImageTextButton& target, const UIInventorySlotStyle& style, bool clone = false);
    void SetInventorySlotData(const UIImageTextButton& target, const UIInventorySlotData* data);
    void UpdateInventorySlot(const UIImageTextButton& slot, const UIInventorySlotStyle& style,
                             const UIInventorySlotData& data, const std::function<void()>& callback = nullptr);
    void ApplyIconStyle(UIImageTextButton& target, const UIIconStyle& style, bool clone = false);
    void ApplyButtonStyle(UIImageTextButton& target, const UIButtonStyle& style, bool clone = false);
    void SetButtonText(const UIImageTextButton& btn, const std::wstring& text, size_t index = 0);
    void SetButtonImage(const UIImageTextButton& btn, const ImageStyle& style, size_t index = 0);

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