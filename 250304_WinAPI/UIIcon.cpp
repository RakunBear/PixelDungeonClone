#include "UIIcon.h"
#include "D2DImage.h"
#include "D2DImageManager.h"

using namespace UI;

void UIIcon::Init(UIObject* parent, FRECT rect, FPOINT scale,
	ImageData imgData, ImageData bgData, FRECT margin)
{
	UIObject::Init(parent, rect, scale);
	this->margin = margin;

	ResourceInit(imgData, bgData);
}

void UI::UIIcon::Init(UIObject* parent, int dx, int dy, int width, int height, FPOINT scale, 
	ImageData imgData, ImageData bgData, FRECT margin)
{
	UIObject::Init(parent, dx, dy, width, height, scale);

	ResourceInit(imgData, bgData);
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
		bg->RenderFrameScale(worldTransform.transform.left, worldTransform.transform.top, worldTransform.scale.x, worldTransform.scale.y, 0, 0);
	}
	if (icon)
	{
		icon->RenderFrameScale( worldTransform.transform.left + margin.left, worldTransform.transform.top + margin.top, worldTransform.scale.x, worldTransform.scale.y, 0, 0);
	}
}

void UIIcon::ResourceInit( ImageData imgData, ImageData bgData )
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
