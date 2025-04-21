#pragma once
#include "../Core/UIComponent.h"
#include "../../D2DImage.h"
#include "../VisualStyle.h"


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

    void SetImage(D2DImage* image)
    {
        style.image = image;
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

    void Render(ID2D1HwndRenderTarget* rt) override {
        if (!isVisible || !isActive) return;
        
        if (!style.image || !rt) return;

        D2D1_RECT_F rect = GetScaledDrawRect();
        FPOINT ws = GetWorldScale();

        style.image->RenderFrameScale(rect.left, rect.top, ws.x, ws.y, 0, 0, 
            0.0f, false, false, style.alpha);
    

        // 🔸 출력 영역 확인용 사각형 (얇은 외곽선)
        ID2D1SolidColorBrush* debugBrush = nullptr;
        rt->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::Red), &debugBrush);
        rt->DrawRectangle(rect, debugBrush, 1.0f);  // 1.0f: 선 두께

        if (debugBrush) debugBrush->Release();
    }
};
