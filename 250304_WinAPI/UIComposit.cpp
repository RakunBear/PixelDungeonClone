#include "UIComposit.h"

using namespace UI;

void UI::UIComposit::Init(UIObject* parent, FRECT rect, FPOINT scale)
{
	UIObject::Init(parent, rect, scale);

	ResourceInit();
}

void UI::UIComposit::Init(UIObject* parent, int dx, int dy, int width, int height,
	FPOINT scale)
{
	UIObject::Init(parent, dx, dy, width, height, scale);

	ResourceInit();
}
