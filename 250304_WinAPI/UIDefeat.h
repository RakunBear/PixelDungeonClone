#pragma once
#include "UIComposit.h"

namespace UI
{
	class UIImage;

	class UIDefeat : public UIComposit
	{
	public:
		void Release() override;
		void Update() override;
		void Render() override;
	protected:
		void ResourceInit() override;
	protected:
		UIImage* defeatImage;
	};

}