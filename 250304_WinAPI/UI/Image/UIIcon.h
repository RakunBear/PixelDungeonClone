#pragma once
#include "../Core/UIContainerBase.h"
#include "../../D2DImageManager.h"
#include "../VisualStyle.h"


class UIIcon : public UIContainerBase {
private:
    IconStyle style;

public:
    void Init(const IconStyle& s, const D2D1_RECT_F& layout) {
        style = s;
        SetRect(layout);
    }

    void SetStyle(const IconStyle& s) {
        style = s;
    }

    void Render(ID2D1HwndRenderTarget* rt) override {
        D2D1_RECT_F rect = GetScaledDrawRect();

        // 🔹 배경
        if (style.background.image) {
            style.background.image->RenderFrameScale(rect.left, rect.top,
                scale.x, scale.y, 0, 0, style.background.alpha);
        }

        // 🔹 전경
        if (style.foreground.image) {
            D2D1_RECT_F inner = D2D1::RectF(
                rect.left + style.padding.left,
                rect.top + style.padding.top,
                rect.right - style.padding.right,
                rect.bottom - style.padding.bottom
            );

            style.foreground.image->RenderFrameScale(inner.left, inner.top,
                scale.x, scale.y, 0, 0, style.foreground.alpha);
        }
    }

    void Update(float) override {}
};
