#pragma once
#include <string>
#include "../../D2DImage.h"

struct ImageStyle {
    D2DImage* image = nullptr;
    FRECT padding = {0,0,0,0};
    float alpha = 1.0f;
    D2D1_COLOR_F tint = D2D1::ColorF(1, 1, 1, 1); // 색상 효과
    bool grayscale = false; // 비활성화 상태 표현
};

struct BarStyle {
    ImageStyle background;
    ImageStyle fill;
    ImageStyle handle;
};

struct TextStyle {
    std::wstring fontName = L"맑은 고딕";
    float fontSize = 16.0f;
    D2D1_COLOR_F color = D2D1::ColorF(0, 0, 0, 1); // 기본 검정
    bool bold = false;
    DWRITE_TEXT_ALIGNMENT horizontalAlign = DWRITE_TEXT_ALIGNMENT_LEADING;
    DWRITE_PARAGRAPH_ALIGNMENT verticalAlign = DWRITE_PARAGRAPH_ALIGNMENT_NEAR;
};

struct EffectStyle {
    float lifetime = 1.0f;
    float moveSpeed = -3.0f;
};

// 9개 영역의 이미지 스타일
struct NinePatchStyle {
    ImageStyle topLeft, top, topRight;
    ImageStyle left, center, right;
    ImageStyle bottomLeft, bottom, bottomRight;
    D2D1_SIZE_F cornerSize = { 8.0f, 8.0f };  // 기본 모서리 크기
};

struct UIIconStyle {
    ImageStyle bgStyle{nullptr};
    ImageStyle iconStyle{nullptr};
};

struct UIInventorySlotStyle {
    ImageStyle background;         // 슬롯 배경
    ImageStyle itemIcon;          // 아이템 아이콘 이미지
    TextStyle quantityTextStyle;  // 좌상단 수량 텍스트
    TextStyle enhancementTextStyle; // 우하단 강화 수치 텍스트
};

struct UIButtonStyle {
    ImageStyle background;
    TextStyle textStyle;
};