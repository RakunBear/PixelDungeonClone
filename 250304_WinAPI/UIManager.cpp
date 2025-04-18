#include "UIManager.h"
#include "UIStatus.h"
#include "UIMenueBtns.h"
#include "UIQuickSlot.h"
#include "UIDefeat.h"

using namespace UI;

void UI::UIManager::Init()
{
	ResourceInit();
}

void UI::UIManager::Release()
{
	if (statToolbar)
	{
		statToolbar->Release();
		delete statToolbar;
		statToolbar = nullptr;
	}
	if (menueToolbar)
	{
		menueToolbar->Release();
		delete menueToolbar;
		menueToolbar = nullptr;
	}
	if (quickSlot)
	{
		quickSlot->Release();
		delete quickSlot;
		quickSlot = nullptr;
	}
	if (defeatUI)
	{
		defeatUI->Release();
		delete defeatUI;
		defeatUI = nullptr;
	}
}

void UI::UIManager::Update()
{
	statToolbar->Update();
	menueToolbar->Update();
	quickSlot->Update();
	defeatUI->Update();
}

void UI::UIManager::Render()
{
	RenderIsVisible(statToolbar);
	RenderIsVisible(quickSlot);
	RenderIsVisible(menueToolbar);
	RenderIsVisible(defeatUI);
}

void UI::UIManager::Reset()
{
	Release();
	Init();
}

void UI::UIManager::SetStatus(StatInfo statInfo)
{
	if (statToolbar == nullptr) return;

	statToolbar->SetStatus(statInfo);
}

void UI::UIManager::ShowDefeat(bool flag)
{
	defeatUI->isVisible = flag;
}

void UI::UIManager::SetItemInfo()
{
	if (quickSlot == nullptr) return;
}

void UI::UIManager::ResourceInit()
{
	statToolbar = new UIStatus;
	quickSlot = new UIQuickSlot;
	menueToolbar = new UIMenueBtns;
	defeatUI = new UIDefeat;

	statToolbar->Init(nullptr, { 0.0f, 610.0f, 335, 720 });
	quickSlot->Init(nullptr, { 725.0f, 649.0f, 720 });
	menueToolbar->Init(nullptr, { 922.0f, 0.0f, 1080, 56 });
	defeatUI->Init(nullptr, {0.0f, 0.0f, WINSIZE_X, WINSIZE_Y});
	defeatUI->isVisible = false;
}