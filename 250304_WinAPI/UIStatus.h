#pragma once
#include "UIComposit.h"

class Image;

namespace UI
{
	class UIIcon;
	class UITextBox;
	class UISlider;
	class UIText;

	class UIStatus : public UIComposit
	{
	public:
		~UIStatus() override = default;

		void Release() override;
		void Update() override;
		void Render() override;

		void SetLevel(int level);
		void SetHPAndExp(int maxHP, int hp, int maxExp, int exp);
		void SetStatus(StatInfo statInfo);

	protected:
		void ResourceInit() override;

	public:
		/* Child UI */
		UIIcon* icon;
		UITextBox* levelTextUI;
		UISlider* hpBar;
		UIText* hpText;
		UISlider* expBar;
		UIText* expText;

		TextStyle hpTextStyle{ L"", 20, {0, 0, 0, 1.0}};
		TextStyle expTextStyle{ L"", 20, {0, 0, 0, 1.0}};
		TextStyle levelTextStyle{ L"", 20, {0, 0, 0, 1.0}};
	};

}