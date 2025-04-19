#pragma once
#include "UIComponent.h"
#include "VisualStyle.h"
#include "DWriteFactory.h"
#include "D2DBrush.h"

class UITextEffect : public UIComponent {
private:
    std::wstring text;
    TextStyle style;
    float lifetime = 1.0f;   // 총 지속 시간
    float elapsed = 0.0f;    // 경과 시간
    float moveSpeed = -40.0f; // 초당 y 이동량 (위로)
    float startY = 0.0f;

public:
    void Init(const std::wstring& str, const TextStyle& s, float duration = 1.0f) {
        text = str;
        style = s;
        lifetime = duration;
        elapsed = 0.0f;
        startY = GetWorldRect().top;
    }

    void Update(float dt) override {
        elapsed += dt;
        float t = min(elapsed / lifetime, 1.0f);
        style.color.a = 1.0f - t; // 알파 감소

        float yOffset = moveSpeed * t;
        auto r = GetWorldRect();
        r.top = startY + yOffset;
        r.bottom = r.top + (r.bottom - r.top);
        SetWorldRect(r);
    }

    void Render(ID2D1HwndRenderTarget* rt) override {
        auto format = DWriteFactory::GetInstance()->FindFormat(style.fontName, style.fontSize);
        if (!format) return;

        auto brush = D2DBrush(style.color, style.color.a);
        rt->DrawTextW(text.c_str(), text.length(), format, &GetWorldRect(), brush.Get());
    }

    bool IsDead() const { return elapsed >= lifetime; }
};
