#pragma once
#include "../Panel/UIStatusTollbar.h"
#include "../Panel/UIQuickSlotToolbar.h"
#include "../Panel/UITopRightUI.h"
#include "UITestHeader.h" // UITestHeader 정의된 곳 명확히 포함

class UITestView {
private:
	UIStatusToolbar statusToolBar;
	UIQuickSlotToolbar quickSlotToolBar;
	UITopRightUI topRightToolBar;
	UITestHeader uiTester;

public:
	void Init() {
		statusToolBar.Init();
		quickSlotToolBar.Init();
		topRightToolBar.Init();
		uiTester.InitUI();  // logPanel, floatingText 등 포함
	}

	void Release() {
		// 메모리 정리가 필요한 경우 구현
		// 현재는 대부분 new/delete 처리됨 → 생략 가능
	}

	void Update(float dt) {
		statusToolBar.Update(dt);
		quickSlotToolBar.Update(dt);
		topRightToolBar.Update(dt);
		uiTester.UpdateUI(dt);  // 로그/이펙트
	}

	void Render(ID2D1HwndRenderTarget* rt) {
		statusToolBar.Render(rt);
		quickSlotToolBar.Render(rt);
		topRightToolBar.Render(rt);
		uiTester.RenderUI(rt);  // 로그/이펙트
	}

	void Reset() {
		Release();
		Init();
	}

	// UI에 대한 접근이 필요한 경우 getter 추가
	UIStatusToolbar* GetStatusToolbar() { return &statusToolBar; }
	UIQuickSlotToolbar* GetQuickSlotToolbar() { return &quickSlotToolBar; }
	UITopRightUI* GetTopRightUI() { return &topRightToolBar; }
};
