#pragma once
#include "UIComposit.h"

namespace UI
{
	class UISlider;
	class UIMopHPBar : public UIComposit
	{
	public:
		void Release() override;
		void Update() override;
		void Render() override;

		void SetPos(float dx, float dy) override;
		void SetMaxHP(int hp);
		void SetHP(int hp);
	protected:
		void ResourceInit() override;

	protected:
		UISlider* hpBar;
	};

}