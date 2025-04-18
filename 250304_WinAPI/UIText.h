#pragma once
#include "UIObject.h"
#include "D2DTextRenderer.h"

class D2DTextRenderer;

namespace UI
{
	class UIText : public UIObject
	{
	public:
		~UIText() override = default;
		void Init(UIObject* parent, FRECT rect,  
			FPOINT scale = { 1.0f, 1.0f });
		void Init(UIObject* parent, int dx, int dy, int width, int height, 
			FPOINT scale = { 1.0f, 1.0f });

		void Release() override;
		void Update() override;
		void Render() override;
		
		void SetPos(float dx, float dy) override;
		void SetTextStyle(const TextStyle& style) 
		{ 
			text = style.content;
			fontSize = style.fontSize;
			color =
			{
				style.colorA.r,
				style.colorA.g,
				style.colorA.b,
				style.colorA.a
			};
		}

	protected:
		virtual void ResourceInit();

	protected:
		D2DTextRenderer* m_pTextRenderer{ nullptr };
		wstring text = L"asda";
		D2D1_RECT_F layout = D2D1::RectF();
		float fontSize{ 10.0f };
		D2D1::ColorF color{ 1.0f, 1.0f, 1.0f, 1.0f };
		Image* bg;
	};

}