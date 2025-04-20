#pragma once
#include "../VisualStyle.h"

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