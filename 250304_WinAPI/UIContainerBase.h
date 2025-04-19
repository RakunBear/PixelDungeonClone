#pragma once
#include "UIComponent.h"

class UIContainerBase : public UIComponent {
protected:
    std::vector<UIComponent*> children;

public:
    virtual ~UIContainerBase() {
        for (auto* c : children) {
            delete c;
        }
        children.clear();
    }

    virtual void AddChild(UIComponent* child) {
        if (!child) return;
        child->SetParent(this);         // 자식에게 부모 지정
        children.push_back(child);
        child->UpdateWorldRect();
    }   

    void RemoveChild(UIComponent* target, bool isDelete = true) {
        if (!target) return;

        auto it = std::find(children.begin(), children.end(), target);
        if (it != children.end()) {
            children.erase(it);
            target->SetParent(nullptr); // 부모 해제
            if (isDelete)
            {
                delete target;
            }
            target = nullptr;
        }
    }

    const std::vector<UIComponent*>& GetChildren() const {
        return children;
    }

    void SetRect(const D2D1_RECT_F& rect) override {
        UIComponent::SetRect(rect);  // ✅ 부모 위치 갱신

        // ✅ 자식 위치 재계산
        for (auto* c : children) {
            c->UpdateWorldRect();  // localRect → worldRect 변환
        }
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

    void UpdateWorldRect() override {
        UIComponent::UpdateWorldRect();
        for (auto* c : children)
            c->UpdateWorldRect();
    }
};
