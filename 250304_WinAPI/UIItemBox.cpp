#include "UIItemBox.h"
#include "UIText.h"
#include "UIIcon.h"
#include "ImageManager.h"
#include "CommonFunction.h"


using namespace UI;

void UIItemBox::Release()
{
	UIButton::Release();
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

	if (textUI2)
	{
		textUI2->Render();
	}

	if (itemIcon)
	{
		itemIcon->Render();
	}
}

void UIItemBox::SetText2(const string& str)
{
	if (textUI2)
	{
		textUI2->SetText(str);
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
	textUI->SetRect({ 0,0, size.x, size.y/2 });
	textUI->SetText("TESTSTMI");

	textUI2 = new UIText;
	textUI2->Init(nullptr, { 0, size.y/2, size.x, size.y }, "ㄴㄹㄴㄹㄴ");

	itemIcon = new UIIcon;
}
