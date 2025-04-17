#include "UIDefeat.h"
#include "ImageManager.h"
#include "UIImage.h"
#include "CommonFunction.h"

void UI::UIDefeat::Release()
{
    if (defeatImage)
    {
        defeatImage->Release();
        delete defeatImage;
        defeatImage = nullptr;
    }
}

void UI::UIDefeat::Update()
{
    defeatImage->Update();
}

void UI::UIDefeat::Render()
{
    if (defeatImage)
    {
        defeatImage->Render();
    }
}

void UI::UIDefeat::ResourceInit()
{
    defeatImage = new UIImage();
    defeatImage->Init(this, CaculateRelativeRECT(rectTransform, { 0, 0, width/3, height/5}),
        ImageData{ "defeat_img", L"assets/interfaces/defeat_img.png", true, RGB(255, 255, 255) });
    defeatImage->SetPos(centerX, height / 3);
}
