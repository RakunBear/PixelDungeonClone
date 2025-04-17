#include "UIIcon.h"
#include "D2DImage.h"
#include "D2DImageManager.h"

using namespace UI;

void UIIcon::Init(UIObject* parent, RECT rect, ImageData imgData, ImageData bgData, RECT margin)
{
	UIObject::Init(parent, rect);

	ResourceInit(imgData, bgData, margin);
}

void UIIcon::Init(UIObject* parent, int dx, int dy, int width, int height, ImageData imgData, ImageData bgData, RECT margin)
{
	UIObject::Init(parent, dx, dy, width, height);

	ResourceInit(imgData, bgData, margin);
}

void UIIcon::Release()
{
	if (icon)
	{
		icon = nullptr;
	}

	if (bg)
	{
		bg = nullptr;
	}
}

void UIIcon::Update()
{
}

void UIIcon::Render()
{
	if (bg)
	{
		bg->RenderFrameScale(rectTransform.left, rectTransform.top, 1.0f, 1.0f, 0, 0);
	}
	if (icon)
	{
		icon->RenderFrameScale( rectTransform.left + margin.left, rectTransform.top + margin.top, 1.0f, 1.0f, 0, 0);
	}
}

void UIIcon::ResourceInit( ImageData imgData, ImageData bgData, RECT margin )
{
	this->margin = margin;

	if (imgData.keyName != "")
	{
		icon = D2DImageManager::GetInstance()->AddImage(imgData.keyName, imgData.filePath);
	}

	if (bgData.keyName != "")
	{
		bg = D2DImageManager::GetInstance()->AddImage(bgData.keyName, bgData.filePath);
		return;
	}
}
