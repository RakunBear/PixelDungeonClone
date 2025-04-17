#pragma once
#include "UIObject.h"

class D2DImage;

namespace UI
{

	class UIImage : public UIObject
	{
	public:
		~UIImage() override = default;

		void Init(UIObject* parent, FRECT rect, 
			FPOINT scale = { 1.0f, 1.0f }, ImageData imgData = { "", L"", 0, 0 });
		void Init(UIObject* parent, int dx, int dy, int width, int height,
			FPOINT scale = { 1.0f, 1.0f }, ImageData imgData = { "", L"", 0, 0 });
		void Release() override;
		void Update() override;
		void Render() override;

	protected:
		void ResourceInit(ImageData imgData = { "", L"", 0, 0 });

	protected:
		D2DImage* img;
	};

}