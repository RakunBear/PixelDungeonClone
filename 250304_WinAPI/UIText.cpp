#include "UIText.h"
#include "D2DImage.h"
#include "D2DTextRenderer.h"

using namespace UI;

void UIText::Init(UIObject* parent, FRECT rect, FPOINT scale)
{
	UIObject::Init(parent, rect, scale);

	ResourceInit();
}

void UIText::Init(UIObject* parent, int dx, int dy, int width, int height, 
	FPOINT scale)
{
	UIObject::Init(parent, dx, dy, width, height, scale);
	
	ResourceInit();
}

void UIText::Release()
{
	if (m_pTextRenderer)
	{
		delete m_pTextRenderer;
		m_pTextRenderer = nullptr;
	}
}

void UIText::Update()
{
}

void UIText::Render()
{
	m_pTextRenderer->DrawText(text, layout, fontSize, {1.0f,1.0f,1.0f,1.0f});
}

void UI::UIText::SetPos(float dx, float dy)
{
	UIObject::SetPos(dx, dy);

	layout.left = worldTransform.transform.left;
	layout.top = worldTransform.transform.top;
	layout.right = worldTransform.transform.right;
	layout.bottom = worldTransform.transform.bottom;
}

void UI::UIText::ResourceInit()
{
	layout.left = worldTransform.transform.left;
	layout.top = worldTransform.transform.top;
	layout.right = worldTransform.transform.right;
	layout.bottom = worldTransform.transform.bottom;

	ID2D1RenderTarget* renderTarget = D2DImage::GetRenderTarget();
	m_pTextRenderer = new D2DTextRenderer(renderTarget);
}
