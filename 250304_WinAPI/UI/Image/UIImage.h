#pragma once
#include "../Core/UIComponent.h"
#include "../../D2DImage.h"


class UIImage : public UIComponent {
protected:
    ImageStyle style;

public:
    void Init(const ImageStyle& s, const D2D1_RECT_F& layout) {
        SetRect(layout);
        SetStyle(s);
    }

    void SetStyle(const ImageStyle& s)
    {
        style = s;
        
        D2D1_RECT_F rect = GetLocalRect();
        // 🔹 padding 적용
        rect.left   += style.padding.left;
        rect.top    += style.padding.top;
        rect.right  -= style.padding.right;
        rect.bottom -= style.padding.bottom;
        
        SetRect(rect);
    }

    POINT GetImgSize()
    {
        if (!style.image)
        {
            return
            {
                style.image->GetWidth(),
                style.image->GetHeight()
            };
        }
        return { 0, 0 };
    }

    void Update(float dt) override {}

    void Render(ID2D1HwndRenderTarget* rt) override {
        if (!style.image || !rt) return;

        D2D1_RECT_F rect = GetScaledDrawRect();
        FPOINT ws = GetWorldScale();

        style.image->RenderFrameScale(rect.left, rect.top, ws.x, ws.y, 0, 0, style.alpha);
    }
};
