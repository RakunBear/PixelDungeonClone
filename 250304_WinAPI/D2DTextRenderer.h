#pragma once
#include "config.h"
#include <wrl.h>
using Microsoft::WRL::ComPtr;

struct D2DTextStyle {
    std::wstring content;
    D2D1_RECT_F layout;
    float fontSize;
    D2D1_COLOR_F color;
    float opacity{ 1.0f }; // 알파 효과용
};

class D2DTextRenderer
{
public:
    D2DTextRenderer(ID2D1RenderTarget* renderTarget);
    ~D2DTextRenderer();

    void DrawText(const wstring& content, D2D1_RECT_F layout, float fontSize, D2D1::ColorF color);
    void InitCustomont();

private:
    IDWriteFactory* pDWriteFactory = nullptr;
    IDWriteTextFormat* pTextFormat = nullptr;
    ID2D1RenderTarget* pRenderTarget = nullptr;
    ID2D1SolidColorBrush* pBrush = nullptr;
};
