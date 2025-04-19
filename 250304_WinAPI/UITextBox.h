#pragma once
#include "UIComponent.h"
#include "VisualStyle.h"
#include "UIImage.h"
#include "UIText.h"

// ✅ 복합 UI: 배경 + 텍스트
class UITextBox : public UIComponent {
private:
    UIImage* background = nullptr; // 선택적
    UIText* text = nullptr;        // 필수

public:
    void Init(const TextBoxStyle& style, const std::wstring& content, const D2D1_RECT_F& layout) {
        SetRect(layout);

        if (style.background.image) {
            background = new UIImage();
            background->Init(style.background, layout);
            background->SetParent(this);
        }

        text = new UIText();
        text->Init(content, layout, style.textStyle);
        text->SetParent(this);
    }

    void SetText(const std::wstring& t) {
        if (text) text->SetText(t);
    }

    void SetRect(const D2D1_RECT_F& r) {
        UIComponent::SetRect(r);
        if (background) background->SetRect(r);
        if (text) text->SetRect(r);
    }

    void Update(float dt) override {
        if (background) background->Update(dt);
        if (text) text->Update(dt);
    }

    void Render(ID2D1HwndRenderTarget* rt) override {
        if (background) background->Render(rt);
        if (text) text->Render(rt);
    }
};
