#pragma once
#include "UIObject.h"

class D2DImage;

namespace UI
{
	class UIText;

	class UITextBox : public UIObject
	{
	public:
		~UITextBox() override = default;

		void Init(UIObject* parent, RECT rect, const string& text = "", ImageData bgData = { "", L"", 0, 0 }, RECT margin = { 0,0,0,0 });
		void Init(UIObject* parent, int dx, int dy, int width, int height, const string& text="", ImageData bgData = {"", L"", 0, 0}, RECT margin = { 0,0,0,0 });
		void Release() override;
		void Update() override;
		void Render() override;

		void SetText(const string& text);

	protected:
		void ResourceInit(const string& text="", ImageData bgData = {"", L"", 0, 0}, RECT margin = { 0,0,0,0 });

	protected:
		UIText* textUI;
		D2DImage* bg;

	};

}