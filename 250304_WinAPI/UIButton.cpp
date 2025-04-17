#include "UIButton.h"
#include "UIText.h"

using namespace UI;

void UIButton::Release()
{
	if (textUI)
	{
		textUI->Release();
		delete textUI;
		textUI = nullptr;
	}

	UIIcon::Release();
}

void UIButton::Update()
{
}

void UIButton::Render()
{
	UIIcon::Render();
	if (textUI)
	{
		textUI->Render();
	}
}

void UIButton::SetText(string& txt)
{
	if (textUI)
	{
		textUI->SetText(txt);
	}
}

void UIButton::ResourceInit(ImageData imgData, ImageData bgData)
{
	UIIcon::ResourceInit(imgData, bgData);
	textUI = new UIText();
	textUI->Init(nullptr, localTransform.transform);
}
