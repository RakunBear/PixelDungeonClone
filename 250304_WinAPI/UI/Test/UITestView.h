#pragma once
#include "../Panel/UIStatusTollbar.h"
#include "../Panel/UIQuickSlotToolbar.h"
#include "../Panel/UITopRightUI.h"
#include "UITestHeader.h"
#include "../../config.h"
#include "../Util/UIHelper.h"

class UITestView 
{
private:
	UIStatusToolbar statusToolBar;
	UIQuickSlotToolbar quickSlotToolBar;
	UITopRightUI topRightToolBar;
	UITestHeader uiTester;
	UITestInventoryView uiInventoryView;
	UIAutoContainer uiAutoTestMenu;

	POINT mousePoint;
	float mOffset = 10.0f;

	std::vector<IUIInteractable*> invenInteractables;
	std::vector<UIContainerBase*> rootComponents;

public:
	void Init() {
		statusToolBar.Init();
		quickSlotToolBar.Init();
		topRightToolBar.Init();
		uiTester.InitUI();  // logPanel, floatingText 등 포함
		uiInventoryView.Init();
		uiAutoTestMenu.Init({100,400,200,0});

		rootComponents.push_back(&statusToolBar);
		rootComponents.push_back(&quickSlotToolBar);
		rootComponents.push_back(&topRightToolBar);
		rootComponents.push_back(&uiAutoTestMenu);
		rootComponents.push_back(uiInventoryView.inventoryPanel);

		UIButtonStyle buttonStyle;
		buttonStyle.background = {D2DImageManager::GetInstance()->FindImage("inventory_slot")};
		buttonStyle.textStyle = { L"pixel", 14.0f, D2D1::ColorF(D2D1::ColorF::White) };
		auto onCLick = [this]()
		{
			statusToolBar.SetActive(!statusToolBar.IsActive());
		};
		auto* button = UIHelper::ApplyButtonStyle(uiAutoTestMenu,{0,0,200,50},
			buttonStyle, onCLick);
		UIHelper::SetButtonText(*button, L"스탯용", 0);

		invenInteractables = uiInventoryView.inventoryPanel->GetInteractables();
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
		uiAutoTestMenu.Update(dt);

		uiTester.UpdateUI(dt);  // 로그/이펙트

		// 입력 인식 안되면 A 글자키 입력 후, 마우스 클릭
		if (KeyManager::GetInstance()->IsOnceKeyDown(VK_LBUTTON))
		{
			GetCursorPos(&mousePoint);
			GetCursorPos(&mousePoint); // 화면 기준 마우스 좌표 가져오기
			ScreenToClient(g_hWnd, &mousePoint); // hWnd는 대상 창 핸들

			// // IUIInteractable 인터페이스(태그) 상속하는 애들
			// for (auto interactable : invenInteractables)
			// {
			// 	interactable->HandleClick(mousePoint.x, mousePoint.y);
			// }

			for (auto& rootComponent : rootComponents)
			{
				if (rootComponent->HandleClick(mousePoint.x, mousePoint.y))
				{
					OutputDebugStringA("AAAAA\n");
				}
			}
		}
		else if (KeyManager::GetInstance()->IsOnceKeyDown('C'))
		{
			statusToolBar.SetActive(!statusToolBar.IsActive());
		}
	}

	void Render(ID2D1HwndRenderTarget* rt) {

		statusToolBar.Render(rt);
		quickSlotToolBar.Render(rt);
		topRightToolBar.Render(rt);
		uiInventoryView.Render(rt);
		uiAutoTestMenu.Render(rt);

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
