#pragma once
#include "../Core/UIComponent.h"
#include "../VisualStyle.h"
#include "../../DWriteFactory.h"

class UIText : public UIComponent {
private:
    std::wstring text;
    TextStyle style;

    IDWriteTextFormat* format = nullptr;
    ID2D1SolidColorBrush* brush = nullptr;

public:
    ~UIText() override {
        if (format) format->Release();
        if (brush) brush->Release();
    }

    void Init(const TextStyle& s, const std::wstring& txt, const D2D1_RECT_F& layout) {
        SetRect(layout);

        text = txt;
        style = s;

        DWriteFactory::GetInstance()->CreateTextFormat(
            style.fontName,
            &format,
            style.fontSize,
            style.bold,
            style.horizontalAlign,
            style.verticalAlign
        );
    }

    void SetText(const std::wstring& txt) {
        text = txt;
    }

    void SetStyle(const TextStyle& s) {
        style = s;
        if (format) { format->Release(); format = nullptr; }

        DWriteFactory::GetInstance()->CreateTextFormat(
            style.fontName,
            &format,
            style.fontSize,
            style.bold,
            style.horizontalAlign,
            style.verticalAlign
        );

        if (brush) { brush->Release(); brush = nullptr; }
    }

    TextStyle& GetStyle() {
        return style;
    }

    void Update(float) override {}

    void Render(ID2D1HwndRenderTarget* rt) override {
        if (!brush && rt)
        {
            rt->CreateSolidColorBrush(style.color, &brush);
        }
        if (format && brush)
        {

            D2D1_RECT_F rect = GetScaledDrawRect();

            rt->DrawTextW(text.c_str(), static_cast<UINT32>(text.length()), format, &rect, brush);
        }


    }

};
