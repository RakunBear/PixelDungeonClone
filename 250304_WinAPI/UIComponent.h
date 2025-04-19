#pragma once
#include <d2d1.h>
#include <vector>

class UIComponent {
protected:
    UIComponent* parent = nullptr;

    D2D1_RECT_F localRect{};   // 부모 기준 위치
    D2D1_RECT_F worldRect{};   // 실제 화면 위치
    FPOINT scale = { 1.0f , 1.0f };

public:
    virtual ~UIComponent() = default;

    virtual void Update(float dt) = 0;
    virtual void Render(ID2D1HwndRenderTarget* rt) = 0;

    virtual void SetScale(FPOINT s) {
        this->scale = s;
    }
    FPOINT GetScale() const { return scale; }

    // ✅ scale 반영된 실제 그릴 영역 반환
    D2D1_RECT_F GetScaledDrawRect() const {
        D2D1_RECT_F r = GetWorldRect();
        FPOINT ws = GetWorldScale();

        float width = (r.right - r.left) * ws.x;
        float height = (r.bottom - r.top) * ws.y;

        float centerX = (r.left + r.right) * 0.5f;
        float centerY = (r.top + r.bottom) * 0.5f;

        return D2D1::RectF(
            centerX - width * 0.5f,
            centerY - height * 0.5f,
            centerX + width * 0.5f,
            centerY + height * 0.5f
        );
    }


    // 월드 scale 반영 (재귀)
    FPOINT GetWorldScale() const {
        if (parent)
        {
            FPOINT ps = parent->GetWorldScale();
            return { scale.x * ps.x, scale.y * ps.y };
        }
        return scale;
    }


    // 절대 좌표 지정
    virtual void SetWorldRect(const D2D1_RECT_F& rect) {
        worldRect = rect;
        UpdateLocalRect();
    }

    void SetLocalRect(const D2D1_RECT_F& rect) { SetRect(rect); }
    virtual void SetRect(const D2D1_RECT_F& rect) {
        localRect = rect;
        UpdateWorldRect();
    }

    void SetParent(UIComponent* p) {
        parent = p;
        UpdateWorldRect();

    }

    void AddChild(UIComponent* c) {
        if (!c) return;
        c->SetParent(this);
    }

    virtual void UpdateLocalRect() {
        float width = worldRect.right - worldRect.left;
        float height = worldRect.bottom - worldRect.top;

        if (parent) {
            D2D1_RECT_F parentWorld = parent->GetWorldRect();

            localRect.left = worldRect.left - parentWorld.left;
            localRect.top = worldRect.top - parentWorld.top;
            localRect.right = localRect.left + width;
            localRect.bottom = localRect.top + height;
        }
        else {
            localRect = D2D1::RectF(0, 0, width, height);
        }
    }

    virtual void UpdateWorldRect() {
        if (parent) {
            D2D1_RECT_F parentWorld = parent->GetWorldRect();

            float width = localRect.right - localRect.left;
            float height = localRect.bottom - localRect.top;

            worldRect.left = parentWorld.left + localRect.left;
            worldRect.top = parentWorld.top + localRect.top;
            worldRect.right = worldRect.left + width;
            worldRect.bottom = worldRect.top + height;
        }
        else {
            worldRect = localRect;
        }
    }

    D2D1_RECT_F GetWorldRect() const { return worldRect; }
    D2D1_RECT_F GetLocalRect() const { return localRect; }
};
