#pragma once

#include "../Core/UIContainerBase.h"
#include "../Image/UIImage.h"
#include "../Button/UIButton.h"
#include "../Text/UIText.h"
#include "../VisualStyle.h"
#include <vector>
#include <functional>

class UIImageTextButton : public UIContainerBase {
private:
    std::vector<UIImage*> images;
    std::vector<UIText*> texts;
    UIButton* clickArea = nullptr;
    
public:
    void AddImage(const ImageStyle& imageStyle, const D2D1_RECT_F& rect)
    {
        auto* img = new UIImage();
        img->Init(imageStyle, rect);
        AddChild(img);
        images.push_back(img);
    }
    
    void AddText(const std::wstring& content, const TextStyle& style, const D2D1_RECT_F& layout) {
        auto* txt = new UIText();
        txt->Init(style, content, layout);
        AddChild(txt);
        texts.push_back(txt);
    }

    void AddButton(const D2D1_RECT_F& rect, std::function<void()> fn = nullptr)
    {
        clickArea = new UIButton();
        AddChild(clickArea);
        clickArea->SetOnClick(fn);
    }

    void SetOnClick(std::function<void()> fn) {
        if (clickArea == nullptr)
        {
            return;
        }
        clickArea->SetOnClick(fn);
        
    }

    const std::vector<UIText*>& GetTexts() const {
        return texts;
    }

    // void Render(ID2D1HwndRenderTarget* rt) override {
    //     if (!rt) return;
    //
    //     for (auto* txt : images) {
    //         if (txt) txt->Render(rt);
    //     }
    //     for (auto* txt : texts) {
    //         if (txt) txt->Render(rt);
    //     }
    //     if (clickArea) clickArea->Render(rt); // 버튼 효과가 렌더에 필요하다면
    // }
};
