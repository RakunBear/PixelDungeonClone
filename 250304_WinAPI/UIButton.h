#pragma once
#include "UIComponent.h"
#include "UIImage.h"
#include "VisualStyle.h"
#include "IUIInteractable.h"
#include <functional>

class UIButton : public UIComponent, public IUIInteractable {
private:
    ImageStyle style;             // 🔹 스타일 저장
    UIImage* imageView = nullptr;
    std::function<void()> onClick;

public:
    void Init(const ImageStyle& s) {
        style = s;

        imageView = new UIImage();
        imageView->SetStyle(style);
        imageView->SetRect({ 0, 0, 0, 0 });
        imageView->SetScale({ 1.0f, 1.0f });
    }

    void SetOnClick(std::function<void()> fn) {
        onClick = fn;
    }

    void Render(ID2D1HwndRenderTarget* rt) override {
        if (imageView) {
            imageView->SetRect(GetWorldRect());     // 버튼 자체 좌표에 맞춤
            imageView->SetScale(GetScale());        // 버튼 scale과 일치
            imageView->Render(rt);
        }
    }

    void Update(float dt) override {
        if (imageView) imageView->Update(dt);
    }

    const ImageStyle& GetStyle() const { return style; }
    void SetStyle(const ImageStyle& s) {
        style = s;
        if (imageView)
            imageView->SetStyle(style);
    }

    bool HandleClick(int x, int y) override {
        auto r = GetScaledDrawRect();
        if (x >= r.left && x <= r.right &&
            y >= r.top && y <= r.bottom) {
            if (onClick) onClick();
            return true;
        }
        return false;
    }
};
