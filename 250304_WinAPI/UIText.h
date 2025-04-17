#pragma once
#include "UIObject.h"

namespace UI
{

	class UIText : public UIObject
	{
	public:
		~UIText() override = default;
		void Init(UIObject* parent, FRECT rect,  
			const string& text = "", COLORREF textColor = RGB(0, 0, 0), FPOINT scale = { 1.0f, 1.0f });
		void Init(UIObject* parent, int dx, int dy, int width, int height, 
			const string& text = "", COLORREF textColor = RGB(0, 0, 0), FPOINT scale = { 1.0f, 1.0f });
		void Release() override;
		void Update() override;
		void Render() override;
		void SetText(const string& text) { this->text = text; }
		void SetTextColor(COLORREF color) { this->textColor = color; }

	protected:
		virtual void ResourceInit();

	protected:
		string text;
		COLORREF textColor{ RGB(0, 0, 0) };
		Image* bg;
	};

}