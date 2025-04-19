#pragma once
#include "UIValueBar.h"

// =======================
class PlayerHPBar : public UIValueBar {
public:
    void SetLayout();
};

inline void PlayerHPBar::SetLayout() {
    SetRect(D2D1::RectF(50.0f, 30.0f, 250.0f, 50.0f));
}


// =======================
class BossHPBar : public UIValueBar {
public:
    void SetLayout();
};

inline void BossHPBar::SetLayout() {
    SetRect(D2D1::RectF(300.0f, 20.0f, 980.0f, 40.0f));
}


// =======================
class MonsterHPBar : public UIValueBar {
private:
    D2D1_POINT_2F worldPosition;
    D2D1_SIZE_F baseSize;
};