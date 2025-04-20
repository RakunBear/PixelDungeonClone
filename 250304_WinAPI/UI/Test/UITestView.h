#pragma once
#include "../Panel/UIStatusTollbar.h"
#include "../Panel/UIQuickSlotToolbar.h"
#include "../Panel/UITopRightUI.h"
#include "UITestHeader.h"
#include "../../config.h"

class UITestView 
{
private:
	UIStatusToolbar statusToolBar;
	UIQuickSlotToolbar quickSlotToolBar;
	UITopRightUI topRightToolBar;
	UITestHeader uiTester;
	UITestInventoryView uiInventoryView;

	POINT mousePoint;
	float mOffset = 10.0f;

public:
	void Init() {
		statusToolBar.Init();
		quickSlotToolBar.Init();
		topRightToolBar.Init();
		uiTester.InitUI();  // logPanel, floatingText 등 포함
		uiInventoryView.Init();
	}

	void Release() {
		// 메모리 정리가 필요한 경우 구현
		// 현재는 대부분 new/delete 처리됨 → 생략 가능
	}

	void Update(float dt) {
		statusToolBar.Update(dt);
		quickSlotToolBar.Update(dt);
		topRightToolBar.Update(dt);
		uiInventoryView.Update(dt);

		uiTester.UpdateUI(dt);  // 로그/이펙트

		if (KeyManager::GetInstance()->IsStayKeyDown(VK_LBUTTON))
		{
			GetCursorPos(&mousePoint);
			uiInventoryView.HandleClick(mousePoint.x, mousePoint.y);
		}
	}

	void Render(ID2D1HwndRenderTarget* rt) {

		statusToolBar.Render(rt);
		quickSlotToolBar.Render(rt);
		topRightToolBar.Render(rt);
		uiInventoryView.Render(rt);

		uiTester.RenderUI(rt);  // 로그/이펙트

		// TODO : 지우기
		D2D1_RECT_F rect = { mousePoint.x - mOffset, mousePoint.y - mOffset, mousePoint.x + mOffset, mousePoint.y + mOffset };

		// 🔸 출력 영역 확인용 사각형 (얇은 외곽선)
		ID2D1SolidColorBrush* debugBrush = nullptr;
		rt->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::Red), &debugBrush);
		rt->DrawRectangle(rect, debugBrush, 1.0f);  // 1.0f: 선 두께

		if (debugBrush)
			debugBrush->Release();
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
