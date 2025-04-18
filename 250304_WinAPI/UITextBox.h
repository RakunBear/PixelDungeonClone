#pragma once
#include "UIObject.h"

class D2DImage;

namespace UI
{
	class UIText;
	class UIImage;

	class UITextBox : public UIObject
	{
	public:
		~UITextBox() override = default;

		void Init(UIObject* parent, FRECT rect, FPOINT scale = { 1.0f, 1.0f }, 
			ImageData bgData = { "", L"", 0, 0 }, FRECT margin = { 0,0,0,0 });
		void Init(UIObject* parent, int dx, int dy, int width, int height, FPOINT scale = { 1.0f, 1.0f }, 
			ImageData bgData = {"", L"", 0, 0}, FRECT margin = { 0,0,0,0 });
		void Release() override;
		void Update() override;
		void Render() override;

		void SetTextStyle(TextStyle txtStyle);

	protected:
		void ResourceInit(ImageData bgData = {"", L"", 0, 0});

	protected:
		UIText* textUI;
		UIImage* bg;

		FRECT margin;
	};

}