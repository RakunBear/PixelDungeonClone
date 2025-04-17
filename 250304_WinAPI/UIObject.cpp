#include "UIObject.h"

using namespace UI;



void UIObject::Init(UIObject* parent, FRECT relativeRect, FPOINT scale)
{
	SetParent(parent);

	this->localTransform.scale = scale;
	this->localTransform.transform = relativeRect.AplyScale(scale);

	UpdateWorldTransform();
}

void UIObject::Init(UIObject* parent, int dx, int dy, int width, int height, FPOINT scale)
{
	int halfWidth = width / 2;
	int halfHeight = height / 2;
	FRECT rect = { dx - halfWidth, dy - halfHeight, dx + halfWidth, dy + halfHeight };
	
	Init(parent, rect, scale);
}

void UI::UIObject::SetParent(UIObject* parent)
{
	if (parent != nullptr)
	{
		this->parent = parent;
	}
}

void UIObject::SetPos(float dx, float dy)
{
	POINT size = GetSize();
	int halfWidth = size.x / 2;
	int halfHeight = size.y / 2;
	FRECT rect = { dx - halfWidth, dy - halfHeight, dx + halfWidth, dy + halfHeight };
	
	SetRect(rect);
}

void UIObject::SetScale(FPOINT scale)
{
	this->localTransform.scale = scale;

	UpdateWorldTransform();
}

void UI::UIObject::SetSize(int w, int h)
{
	this->localTransform.transform.right = this->localTransform.transform.left + w;
	this->localTransform.transform.bottom = this->localTransform.transform.bottom + h;

	UpdateWorldTransform();
}

void UIObject::SetRect(FRECT rect)
{
	this->localTransform.transform = rect;

	UpdateWorldTransform();
}

void UIObject::UpdateWorldTransform()
{
	if (parent)
	{
		this->worldTransform.scale = parent->worldTransform.scale * this->localTransform.scale;
		this->worldTransform.transform = parent->worldTransform.transform + this->localTransform.transform;
	}
	else
	{
		this->worldTransform.scale = this->localTransform.scale;
		this->worldTransform.transform = this->localTransform.transform;
	}
}
