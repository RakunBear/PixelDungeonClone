#pragma once

class D2DImage;

struct UIInventorySlotData
{
    int itemId = 0;
    D2DImage* icon = nullptr;
    int quantity = 0;
    int enhancement = 0;
};