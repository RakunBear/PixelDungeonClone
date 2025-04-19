#pragma once
#include "UIComponent.h"
#include "D2DImage.h"


class UIImage : public UIComponent {
protected:
    ImageStyle style;

public:
    void Init(const ImageStyle& s, const D2D1_RECT_F& layout) {
        style = s;
        SetRect(layout);
    }

    void SetStyle(const ImageStyle& s) { style = s; }

    void Update(float dt) override {}

    void Render(ID2D1HwndRenderTarget* rt) override {
        if (!style.image || !rt) return;

        D2D1_RECT_F rect = GetScaledDrawRect();
        
        style.image->RenderFrameScale(rect.left, rect.top, scale.x, scale.y, 0, 0, style.alpha);
    }
};
