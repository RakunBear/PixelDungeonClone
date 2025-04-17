#include "UIText.h"

using namespace UI;

void UIText::Init(UIObject* parent, FRECT rect, 
	const string& text, COLORREF textColor, FPOINT scale)
{
	UIObject::Init(parent, rect, scale);

	ResourceInit();
}

void UIText::Init(UIObject* parent, int dx, int dy, int width, int height,
	const string& text, COLORREF textColor, FPOINT scale)
{
	UIObject::Init(parent, dx, dy, width, height, scale);
	
	ResourceInit();
}

void UIText::Release()
{
	if (text != "")
	{
		text.clear();
	}
	if (textColor != RGB(0, 0, 0))
	{
		textColor = RGB(0, 0, 0);
	}
}

void UIText::Update()
{
}

void UIText::Render()
{
	//SetBkMode(TRANSPARENT);
	//SetTextAlign(TA_CENTER | TA_BASELINE);
	//TextOutA(hdc, centerX, centerY, text.c_str(), text.length());
}

void UI::UIText::ResourceInit()
{
	this->text = text;
	this->textColor = textColor;
}
