#include "D2DTextRenderer.h"

D2DTextRenderer::D2DTextRenderer(ID2D1RenderTarget* renderTarget)
    : pRenderTarget(renderTarget)
{
    DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED, __uuidof(IDWriteFactory), (IUnknown**)&pDWriteFactory);

    renderTarget->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::Blue), &pBrush);
}

D2DTextRenderer::~D2DTextRenderer()
{
    if (pBrush) pBrush->Release();
    if (pTextFormat) pTextFormat->Release();
    if (pDWriteFactory) pDWriteFactory->Release();
}

void D2DTextRenderer::DrawText(const wstring& content, D2D1_RECT_F layout, float fontSize, D2D1::ColorF color)
{
    IDWriteTextFormat* pFormat = nullptr;
    pDWriteFactory->CreateTextFormat(
        L"Algerian", nullptr,
        DWRITE_FONT_WEIGHT_NORMAL,
        DWRITE_FONT_STYLE_NORMAL,
        DWRITE_FONT_STRETCH_NORMAL,
        fontSize, L"ko-kr",
        &pFormat
    );

    pBrush->SetColor(D2D1::ColorF(color.r, color.g, color.b, color.a));
    pRenderTarget->DrawTextW(
        content.c_str(), (UINT32)content.length(),
        pFormat, &layout, pBrush
    );

    pFormat->Release();
}
