#pragma once
#include "../Core/UIContainerBase.h"
#include "../VisualStyle.h"
#include "../Image/UIImage.h"
#include "../Text/UIText.h"

// ✅ 복합 UI: 배경 + 텍스트
class UITextBox : public UIContainerBase {
private:
    TextBoxStyle style;
    UIText* text = nullptr;
    UIImage* image = nullptr;

public:
    void Init(const TextBoxStyle& s, const std::wstring& content, const D2D1_RECT_F& layout) {
        style = s;
        SetRect(layout); // 자신의 위치 설정

        if (style.background.image) {
            image = new UIImage;
            image->Init(style.background, { 0, 0, layout.right - layout.left, layout.bottom - layout.top });
            AddChild(image);
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
            image->Render(rt);
        }

        if (text)
        {
            text->Render(rt);
        }
    }
};
