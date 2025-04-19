#pragma once
#include "UIComponent.h"
#include "UILayout.h"

class UIContainer : public UIComponent {
protected:
    std::vector<UIComponent*> children;
    UILayout* layout = nullptr;

public:
    void AddComponent(UIComponent* comp) {
        comp->SetParent(this);
        children.push_back(comp);
        UpdateLayout();
    }

    void SetLayout(UILayout* l) { layout = l; }

    void SetRect(const D2D1_RECT_F& rect) override {
        UIComponent::SetRect(rect);

        if (layout)
        {
            layout->Apply(children, rect);
        }

        for (auto* c : children)
        {
            c->UpdateWorldRect();
        }
    }

    void UpdateLayout() {
        if (layout)
            layout->Apply(children, GetLocalRect());

        for (auto* c : children)
            c->UpdateWorldRect();
    }

    void Update(float dt) override {
        for (auto* c : children) 
        {
            c->Update(dt);
        }
    }

    void Render(ID2D1HwndRenderTarget* rt) override {
        for (auto* c : children) 
        {
            c->Render(rt);
        }
    }
};
