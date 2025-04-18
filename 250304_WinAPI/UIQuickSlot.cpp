#include "UIQuickSlot.h"
#include "UIButton.h"
#include "UIItemBox.h"
#include "CommonFunction.h"


using namespace UI;

void UIQuickSlot::Release()
{
	if (BackpackBtn)
	{
		BackpackBtn->Release();
		delete BackpackBtn;
		BackpackBtn = nullptr;
	}
	if (SlepBtn)
	{
		SlepBtn->Release();
		delete SlepBtn;
		SlepBtn = nullptr;
	}
	if (SearchBtn)
	{
		SearchBtn->Release();
		delete SearchBtn;
		SearchBtn = nullptr;
	}
}

void UIQuickSlot::Update()
{
}

void UIQuickSlot::Render()
{
	if (BackpackBtn)
	{
		BackpackBtn->Render();
	}
	if (SlepBtn)
	{
		SlepBtn->Render();
	}
	if (SearchBtn)
	{
		SearchBtn->Render();
	}
	for (int i = 0; i < ItemBox.size(); ++i)
	{
		//ItemBox[i]->Render();
	}
}

void UIQuickSlot::ResourceInit()
{
	for (int i = 0; i < 3; ++i)
	{
		auto itemBox = new UIItemBox();
		itemBox->Init(this, { 60.1f * i, 5.46f, 55.0f, 67.0f }, { 1.0f, 1.0f },
			ImageData{ "item_quick", L"assets/interfaces/item_quick.png", true, RGB(255, 255, 255) });
		ItemBox.push_back(itemBox);
	}
	SearchBtn = new UIButton();
	SearchBtn->Init(this, { 180.23f, 0.0f, 218.0f, 67.0f }, { 1.0f, 1.0f },
		ImageData{ "search_quick", L"assets/interfaces/search_quick.png", true, RGB(255, 255, 255) });
	SlepBtn = new UIButton();
	SlepBtn->Init(this, { 234.85, 0.0f, 271.0f, 67.0f }, { 1.0f, 1.0f },
		ImageData{ "sleep_quick", L"assets/interfaces/sleep_quick.png", true, RGB(255, 255, 255) });
	BackpackBtn = new UIButton();
	BackpackBtn->Init(this, { 289.46f, 0.0f, 337.0f, 67.0f }, { 1.0f, 1.0f },
		ImageData{ "inven_quick", L"assets/interfaces/inven_quick.png", true, RGB(255, 255, 255) });
}
