#include "UIButton.h"
#include "UIText.h"

using namespace UI;

void UIButton::Release()
{

	UIIcon::Release();
}

void UIButton::Update()
{
}

void UIButton::Render()
{
	UIIcon::Render();
}

void UIButton::ResourceInit(ImageData imgData, ImageData bgData)
{
	UIIcon::ResourceInit(imgData, bgData);
}
