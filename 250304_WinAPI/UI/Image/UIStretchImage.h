#pragma once
#include "../Core/UIComponent.h"
#include "../../D2DImage.h"
#include "../VisualStyle.h"

class UIStretchImage : public UIComponent {
private:
    ImageStyle style;
    bool maintainAspect = true;  // 🔸 true 시 비율 유지

public:
    void Init(const ImageStyle& s, const D2D1_RECT_F& layout, bool keepAspect = true) {
        style = s;
        maintainAspect = keepAspect;
        SetRect(layout);
    }

    void SetStyle(const ImageStyle& s) {
        style = s;
    }

    void SetMaintainAspect(bool flag) {
        maintainAspect = flag;
    }

    void Render(ID2D1HwndRenderTarget* rt) override {
        if (!isVisible || !isActive) return;
        
        if (!style.image || !rt) return;

        D2D1_RECT_F rect = GetWorldRect();
        FPOINT worldScale = GetWorldScale();

        float width = (rect.right - rect.left) * worldScale.x;
        float height = (rect.bottom - rect.top) * worldScale.y;

        // 🔹 비율 유지 시: 원본 비율 기반으로 축소
        if (maintainAspect) {
            int imgW = style.image->GetWidth();
            int imgH = style.image->GetHeight();
            if (imgW > 0 && imgH > 0) {
                float aspect = (float)imgW / (float)imgH;
                float targetAspect = width / height;

                if (targetAspect > aspect) {
                    width = height * aspect;
                } else {
                    height = width / aspect;
                }
            }
        }

        style.image->RenderRaw(rect.left, rect.top, width, height, style.alpha);
    }

    void Update(float) override {}
};
