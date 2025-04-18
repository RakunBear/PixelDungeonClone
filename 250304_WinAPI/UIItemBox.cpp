#include "UIItemBox.h"
#include "UIText.h"
#include "UIIcon.h"
#include "ImageManager.h"
#include "CommonFunction.h"


using namespace UI;

void UIItemBox::Release()
{
	UIButton::Release();
	if (textUI1)
	{
		textUI1->Release();
		delete textUI1;
		textUI1 = nullptr;
	}
	if (textUI2)
	{
		textUI2->Release();
		delete textUI2;
		textUI2 = nullptr;
	}
	if (itemIcon)
	{
		itemIcon->Release();
		delete itemIcon;
		itemIcon = nullptr;
	}
}

void UIItemBox::Render()
{
	UIButton::Render();

	if (textUI1)
	{
		textUI1->Render();
	}
	if (textUI2)
	{
		textUI2->Render();
	}

	if (itemIcon)
	{
		itemIcon->Render();
	}
}

void UIItemBox::SetTextStyle(TextStyle txtStyle1, TextStyle txtStyle2)
{
	if (textUI1)
	{
		textUI1->SetTextStyle(txtStyle1);
	}
	if (textUI2)
	{
		textUI2->SetTextStyle(txtStyle2);
	}
}

void UIItemBox::SetItem(ImageData itemImgData)
{
	itemIcon->Init(nullptr, localTransform.zero(), localTransform.scale, itemImgData);
}

void UIItemBox::ResourceInit(ImageData imgData, ImageData bgData)
{
	UIButton::ResourceInit(imgData, bgData);

	POINT tempSize = GetSize();
	FPOINT size = { tempSize.x, tempSize.y };
	textUI1 = new UIText;
	textUI1->Init(nullptr, { 0,0, size.x, size.y/2 });

	textUI2 = new UIText;
	textUI2->Init(nullptr, { 0, size.y/2, size.x, size.y });

	itemIcon = new UIIcon;
}
