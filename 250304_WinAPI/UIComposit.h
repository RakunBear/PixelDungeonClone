#pragma once
#include "UIObject.h"

namespace UI
{

	class UIComposit : public UIObject
	{
	public:
		virtual ~UIComposit() override = default;
		void Init(UIObject* parent, FRECT relativeRect = { 0.0f,0.0f,0.0f,0.0f }, 
			FPOINT scale = { 1.0f, 1.0f }) override;
		void Init(UIObject* parent = nullptr, int dx = 0, int dy = 0, int width = 0, int height = 0,
			FPOINT scale = { 1.0f, 1.0f }) override;

	protected:
		virtual void ResourceInit() = 0;
	};

}