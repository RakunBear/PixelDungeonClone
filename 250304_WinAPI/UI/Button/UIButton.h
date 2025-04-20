#pragma once
#include "../Core/UIComponent.h"
#include "../Image/UIImage.h"
#include "../VisualStyle.h"
#include "../Utill/IUIInteractable.h"
#include <functional>

class UIButton : public UIComponent, public IUIInteractable {
private:
    std::function<void()> onClick;

public:
    void SetOnClick(std::function<void()> fn = nullptr) {
        onClick = fn;
    }
    
    void Update(float dt) override {}

    void Render(ID2D1HwndRenderTarget* rt) override {
        D2D1_RECT_F rect = GetWorldRect();
        
        // 🔸 출력 영역 확인용 사각형 (얇은 외곽선)
        ID2D1SolidColorBrush* debugBrush = nullptr;
        rt->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::Red), &debugBrush);
        rt->DrawRectangle(rect, debugBrush, 1.0f);  // 1.0f: 선 두께

        if (debugBrush) debugBrush->Release();
    }

    bool HandleClick(int x, int y) override {
        auto r = GetScaledDrawRect();
        if (x >= r.left && x <= r.right &&
            y >= r.top && y <= r.bottom) {
            if (onClick) onClick();
            return true;
        }
        return false;
    }

};
