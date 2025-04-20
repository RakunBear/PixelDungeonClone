#pragma once
#include "../Text/UITextEffect.h"
#include <vector>

class UITestEffectManager {
private:
    std::vector<UITextEffect*> effects;

public:
    ~UITestEffectManager() {
        for (auto* fx : effects) {
            delete fx;
        }
        effects.clear();
    }

    void AddEffect(const std::wstring& text, const TextStyle& style, const D2D1_RECT_F& rect, const EffectStyle& effectStyle) {
        auto* fx = new UITextEffect();
        fx->SetWorldRect(rect);
        fx->Init(text, style, effectStyle);
        effects.push_back(fx);
    }

    void Update(float dt) {
        for (auto it = effects.begin(); it != effects.end(); ) {
            if ((*it)->IsDead()) {
                delete *it;
                it = effects.erase(it);
            }
            else {
                (*it)->Update(dt);
                ++it;
            }
        }
    }

    void Render(ID2D1HwndRenderTarget* rt) {
        for (auto* fx : effects) {
            if (fx)
                fx->Render(rt);
        }
    }

    void Clear() {
        for (auto* fx : effects) {
            delete fx;
        }
        effects.clear();
    }
};
