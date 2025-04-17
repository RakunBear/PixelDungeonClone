#pragma once  
#include "UIObject.h"  

class D2DImage;  

namespace UI  
{  
	class UIIcon : public UIObject  
	{  
	public:  
		UIIcon() = default;
		~UIIcon() override = default;  

		void Init(UIObject* parent, RECT rect,
			ImageData imgData = { "", L"", 0, 0 }, ImageData bgData = { "", L"", 0, 0 }, RECT margin = { 0,0,0,0 });
		void Init(UIObject* parent, int dx, int dy, int width, int height
			, ImageData imgData = { "", L"", 0, 0 }, ImageData bgData = { "", L"", 0, 0 }, RECT margin = { 0,0,0,0 });
		void Release() override;  
		void Update() override;
		void Render() override; 

	protected:
		virtual void ResourceInit(ImageData imgData = { "", L"", 0, 0 }, ImageData bgData = { "", L"", 0, 0 }, RECT margin = { 0,0,0,0 });

	protected:  
		D2DImage* icon;
		D2DImage* bg;

		RECT margin;
	};  
}