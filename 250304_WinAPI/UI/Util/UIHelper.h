#pragma once
#include <d2d1.h>
#include <functional>
#include <string>


struct ImageStyle;
struct UIButtonStyle;
struct UIIconStyle;
struct UIInventorySlotData;
struct UIInventorySlotStyle;
class UIImageTextButton;
class UIContainerBase;


namespace UIHelper {
    /* 생성 코드 */
    UIImageTextButton* ApplyInventorySlotStyle(UIContainerBase& target, const D2D1_RECT_F& localRect, const UIInventorySlotStyle& style,
        const std::function<void()>& onClick = nullptr, bool clone = false);
    UIImageTextButton* ApplyIconStyle(UIContainerBase& target, const D2D1_RECT_F& localRect, const UIIconStyle& style,
        const std::function<void()>& onClick = nullptr, bool clone = false);
    UIImageTextButton* ApplyButtonStyle(UIContainerBase& target, const D2D1_RECT_F& localRect, const UIButtonStyle& style,
        const std::function<void()>& onClick = nullptr, bool clone = false);
    /* 범용 값 변경 코드 */
    void SetButtonText(const UIImageTextButton& btn, const std::wstring& text, size_t index = 0);
    void SetButtonImage(const UIImageTextButton& btn, const ImageStyle& style, size_t index = 0);
    /* 인벤 전용 */
    void SetInventorySlotData(const UIImageTextButton& target, const UIInventorySlotData* data);
    void UpdateInventorySlot(UIImageTextButton& slot, const UIInventorySlotStyle& style,
                             const UIInventorySlotData& data, const std::function<void()>& onClick = nullptr);

    /* 공통 템플릿 및 수학용 */
    float Clamp(float value, float minVal, float maxVal);
    
    template <typename T, typename... Args>
    T* MakeUI(Args&&... args) {
        return new T(std::forward<Args>(args)...);
    }
}
