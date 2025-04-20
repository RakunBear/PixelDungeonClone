#pragma once
#include "../Core/UIContainer.h"
#include "../VisualStyle.h"
#include "../Image/UIStretchImage.h"


class UI9PatchPanel : public UIContainer {
private:
    NinePatchStyle style;

    UIStretchImage* tl = nullptr; UIStretchImage* t = nullptr; UIStretchImage* tr = nullptr;
    UIStretchImage* l = nullptr;  UIStretchImage* c = nullptr; UIStretchImage* r = nullptr;
    UIStretchImage* bl = nullptr; UIStretchImage* b = nullptr; UIStretchImage* br = nullptr;

public:
    void Init(const NinePatchStyle& s, const D2D1_RECT_F& layout) {
        style = s;
        SetRect(layout);

        tl = AddPatch(style.topLeft);
        t  = AddPatch(style.top);
        tr = AddPatch(style.topRight);
        l  = AddPatch(style.left);
        c  = AddPatch(style.center);
        r  = AddPatch(style.right);
        bl = AddPatch(style.bottomLeft);
        b  = AddPatch(style.bottom);
        br = AddPatch(style.bottomRight);

        // ✅ 자식 위치 강제 재배치
        SetRect(layout);  // 다시 한 번 위치 재조정
    }

    UIStretchImage* AddPatch(const ImageStyle& s) {
        if (!s.image) return nullptr;
        auto* img = new UIStretchImage();
        img->Init(s, { 0,0,0,0 });
        AddChild(img);
        return img;
    }

    void SetRect(const D2D1_RECT_F& rect) override {
        UIComponent::SetRect(rect);

        float cornerW = style.cornerSize.width;
        float cornerH = style.cornerSize.height;

        float w = GetWidth();
        float h = GetHeight();

        float centerW = w - cornerW * 2;
        float centerH = h - cornerH * 2;

        if (tl) tl->SetRect({ 0, 0, cornerW, cornerH });
        if (t)  t->SetRect({ cornerW, 0, cornerW + centerW, cornerH });
        if (tr) tr->SetRect({ cornerW + centerW, 0, w, cornerH });

        if (l)  l->SetRect({ 0, cornerH, cornerW, cornerH + centerH });
        if (c)  c->SetRect({ cornerW, cornerH, cornerW + centerW, cornerH + centerH });
        if (r)  r->SetRect({ cornerW + centerW, cornerH, w, cornerH + centerH });

        if (bl) bl->SetRect({ 0, cornerH + centerH, cornerW, h });
        if (b)  b->SetRect({ cornerW, cornerH + centerH, cornerW + centerW, h });
        if (br) br->SetRect({ cornerW + centerW, cornerH + centerH, w, h });
    }
};
