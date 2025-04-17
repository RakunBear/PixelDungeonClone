#pragma once
#include "UIIcon.h"
#include "IButton.h"

namespace UI
{
	class UIText;

	class UIButton : public UIIcon
	{
	public :
		virtual ~UIButton() = default;

		void Release() override;
		void Update() override;
		void Render() override;

		void SetText(string& txt);

	protected:
		void ResourceInit(ImageData imgData, ImageData bgData = { "", L"", 0, 0 }) override;

	protected:
		UIText* textUI;
		COLORREF bgColorRGB{ RGB(0, 0, 0) };
	};

}
