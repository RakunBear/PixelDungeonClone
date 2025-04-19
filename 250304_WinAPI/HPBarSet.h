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

public:
    void SetWorldPosition(D2D1_POINT_2F pos);
    void SetBaseSize(D2D1_SIZE_F sz);
    void UpdateLayout();
};

inline void MonsterHPBar::SetWorldPosition(D2D1_POINT_2F pos) {
    worldPosition = pos;
    UpdateLayout();
}

inline void MonsterHPBar::SetBaseSize(D2D1_SIZE_F sz) {
    baseSize = sz;
    UpdateLayout();
}

inline void MonsterHPBar::UpdateLayout() {
    float width = baseSize.width * scale.x;
    float height = baseSize.height * scale.y;
    SetRect(D2D1::RectF(
        worldPosition.x - width / 2.0f,
        worldPosition.y - height / 2.0f,
        worldPosition.x + width / 2.0f,
        worldPosition.y + height / 2.0f
    ));
}