#pragma once
#include "IButton.h"
#include "UIButton.h"

namespace UI
{
	class UIIcon;
	class UIText;

	class UIItemBox : public UIButton
	{
	public:
		~UIItemBox() override = default;

		void Release() override;
		void Render() override;

		void SetTextStyle(TextStyle txtStyle1, TextStyle txtStyle2);
		void SetItem(ImageData itemImgData);

	protected:
		void ResourceInit(ImageData imgData, ImageData bgData = { "", L"", 0, 0 }) override;

	protected:
		UIText* textUI1;
		UIText* textUI2;
		UIIcon* itemIcon;
	};

}
