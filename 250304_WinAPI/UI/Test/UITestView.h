#pragma once
#include "../Container/Container_FrontUIView.h"

class UITestHeader;

class UITestView
{
public:
	void Init();
	void Release();
	void Update();
	void Render();

	void Reset();

public:
	UIStatusToolbar statusToolBar;
	UIQuickSlotToolbar quickToolBar;
	UITopRightUI topRightToolBar;
	UITestHeader* uiTester;
};
