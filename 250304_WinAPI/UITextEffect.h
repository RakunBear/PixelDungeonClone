#pragma once
#include "UIComponent.h"
#include "VisualStyle.h"
#include "UIText.h"

class UITextEffect : public UIContainerBase {
private:
    UIText* text = nullptr;
    float lifetime = 1.0f;   // 총 지속 시간
    float elapsed = 0.0f;    // 경과 시간
    float moveSpeed = -3.0f; // 초당 y 이동량 (위로)
    float startY = 0.0f;

public:
    void Init(const std::wstring& str, const TextStyle& style, float duration = 1.0f) {
        lifetime = duration;
        elapsed = 0.0f;
        startY = worldRect.top;

        text = new UIText();
        text->Init(style, str, {0, 0, localRect.right, localRect.bottom});
        AddChild(text);
    }

    void Update(float dt) override {
        if (IsDead() || !text) return;

        elapsed += dt;


        // 알파값 줄이기
        TextStyle s = text->GetStyle();
        float t = min(elapsed / lifetime, 1.0f);
        s.color.a = 1.0f - t;
        text->SetStyle(s);

        // 위로 이동
        auto r = text->GetLocalRect();
        float offset = moveSpeed * t;
        r.top = r.top + offset;
        r.bottom = r.bottom + offset;
        text->SetRect(r);
    }

    void Render(ID2D1HwndRenderTarget* rt) override {
        if (!IsDead() && text) {
            text->Render(rt);
        }
    }

    bool IsDead() const { return elapsed >= lifetime; }
};
