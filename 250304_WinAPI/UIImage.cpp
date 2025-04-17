#include "UIImage.h"
#include "D2DImage.h"
#include "D2DImageManager.h"

using namespace UI;

void UI::UIImage::Init(UIObject* parent, RECT rect, ImageData imgData)
{
	UIObject::Init(parent, rect);

	ResourceInit(imgData);
}

void UI::UIImage::Init(UIObject* parent, int dx, int dy, int width, int height, ImageData imgData)
{
	UIObject::Init(parent, dx, dy, width, height);

	ResourceInit(imgData);
}

void UI::UIImage::Release()
{
	if (img)
	{
		img = nullptr;
	}
}

void UI::UIImage::Update()
{
}

void UI::UIImage::Render()
{
	img->Render(rectTransform.left, rectTransform.top);
}

void UI::UIImage::ResourceInit(ImageData imgData)
{
	img = D2DImageManager::GetInstance()->AddImage(imgData.keyName, imgData.filePath);
}
