#include "../Panel/UITextLogPanel.h"
#include "../../Timer.h"
#include "UITestEffectManager.h"

class UITestHeader
{
public:
    // 글로벌 영역 (예시)
    UITextLogPanel* logPanel = nullptr;
    UITestEffectManager effectManager;

    float timer = 0.0f;
    float logInterval = 0.2f; // 2초마다 로그 추가
    Timer timerC;

public:

    // 예시: 입력 처리 후 테스트 트리거
    void OnTestInput() {
        // 샘플 텍스트 목록
        static const std::wstring messages[] = {
            L"Hello, world!",
            L"🔥 Critical Hit!",
            L"You picked up a sword.",
            L"Damage: -25",
            L"Enemy defeated!",
            L"EXP +15",
            L"Level up!"
        };

        // 무작위 색상
        D2D1::ColorF colors[] = {
            D2D1::ColorF::White,
            D2D1::ColorF::Red,
            D2D1::ColorF::Yellow,
            D2D1::ColorF::Cyan,
            D2D1::ColorF::Lime
        };

        int i = rand() % 7;
        int c = rand() % 5;

        TextStyle style;
        style.fontName = L"pixel";
        style.fontSize = 18.0f;
        style.color = colors[c];
        style.horizontalAlign = DWRITE_TEXT_ALIGNMENT_LEADING;
        style.verticalAlign = DWRITE_PARAGRAPH_ALIGNMENT_NEAR;

        logPanel->AddLog(messages[i], style);

        EffectStyle effectStyle =
        {
            5.0f, // duration
            -3.0f // y movespeed value
        };
        D2D1_RECT_F fxRect = { 600, 400, 800, 430 };
        effectManager.AddEffect(messages[i], style, fxRect, effectStyle);
    }

    void InitUI() {
        // UI 생성
        logPanel = new UITextLogPanel();
        logPanel->Init({ 100, 100, 400, 500 }, 6, 20.0f, 2.0f);
        timerC.Init();

    }

    void UpdateUI(float dt) {
        timerC.Tick();
        timer += timerC.GetDeltaTime();
        /////////////////////////////

        if (timer >= logInterval) {
            timer = 0.0f;
            // Test Input
            OnTestInput();

        }
        ////////////////////////


        logPanel->Update(dt);
        effectManager.Update(dt);
    }

    void RenderUI(ID2D1HwndRenderTarget* rt) {
        if (logPanel) logPanel->Render(rt);
        effectManager.Render(rt);
    }
};