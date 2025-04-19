#pragma once
#include "UIComponent.h"
#include "VisualStyle.h"
#include "UIImage.h"
#include "UIText.h"
#include "UIContainerBase.h"

// ✅ 복합 UI: 배경 + 텍스트
class UITextBox : public UIContainerBase {
private:
    TextBoxStyle style;
    UIText* text = nullptr;

public:
    void Init(const TextBoxStyle& s, const std::wstring& content, const D2D1_RECT_F& layout) {
        style = s;
        SetRect(layout); // 자신의 위치 설정

        if (style.background.image) {
            auto* bg = new UIImage();
            bg->Init(style.background, { 0, 0, layout.right - layout.left, layout.bottom - layout.top });
            AddChild(bg); // 배경도 자식으로
        }

        text = new UIText();
        text->Init(style.textStyle, content, { 0, 0, layout.right - layout.left, layout.bottom - layout.top });
        AddChild(text);
    }
 
    void SetText(const std::wstring& t) {
        if (text) text->SetText(t);
    }

    void SetRect(const D2D1_RECT_F& r) {
        UIComponent::SetRect(r);
        if (text) text->Update(1.0f);

    }

    void Update(float dt) override {

    }

    void Render(ID2D1HwndRenderTarget* rt) override {

        D2D1_RECT_F rect = GetScaledDrawRect();

        if (style.background.image)
        {
            D2D1_RECT_F rect = GetScaledDrawRect();
            auto ws = GetWorldScale();
            style.background.image->RenderFrameScale(rect.left, rect.top, ws.x, ws.y, 0, 0, style.background.alpha);
        }

        if (text)
        {
            text->Render(rt);
        }
    }
};
