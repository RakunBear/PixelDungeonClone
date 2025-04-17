#include "UISlider.h"
#include "D2DImage.h"
#include "D2DImageManager.h"

using namespace UI;

void UISlider::Init(UIObject* parent, RECT rect,
    ImageData imgData, ImageData bgData, ImageData handleData, RECT margin)
{
    this->UIObject::Init(parent, rect);

    ResourceInit(imgData, bgData, handleData, margin);
}

void UISlider::Init(UIObject* parent, int dx, int dy, int width, int height,
    ImageData imgData, ImageData bgData , ImageData handleData, RECT margin)
{
    this->UIObject::Init(parent, dx, dy, width, height);

    ResourceInit(imgData, bgData, handleData, margin);
}

void UISlider::Release()
{
    if (fill)
    {
        fill = nullptr;
    }

    if (bg)
    {
        bg = nullptr;
    }

    if (handleImg)
    {
        handleImg = nullptr;
    }
}

void UISlider::Update()
{
    elapsedTime += timeDelta;

    if (currentValue != goalValue && elapsedTime >= 0.016f) // 약 60FPS 기준으로 최소 주기 설정
    {
        currentValue = smoothTime > 0.0f ? SmoothDamp(currentValue, goalValue, currentVelocity, smoothTime, elapsedTime) : goalValue;
        elapsedTime = 0.0f;

        fillValue = max(0.0f, min((currentValue / maxValue), 1.0f));
        
        if (fill)
        {
            UpdateFill();
        }
    }
}

void UISlider::Render()
{
    if (bg)
    {
        bg->Render(rectTransform.left, rectTransform.top);
    }
    if (fill)
    {
        fill->RenderPercent({ (float)fillRectTransfrom.left, (float)fillRectTransfrom.top }, 0.0f, fillValue * 100.0f, 1.0f);
    }
    if (handleImg)
    {
        handleImg->Render(fillRectTransfrom.right, fillRectTransfrom.top);
    }
}

void UI::UISlider::SetPos(int dx, int dy)
{
    UIObject::SetPos(dx, dy);
    fillRectTransfrom = { rectTransform.left + margin.left, rectTransform.top + margin.top,
        rectTransform.left + (int)(width * fillValue), rectTransform.bottom };
}

void UISlider::SetMaxValue(float value)
{
    maxValue = value;

    SetValue(goalValue);
}

void UISlider::SetValue(float value)
{
    goalValue = value;

    UpdateFill();
}

void UISlider::ResourceInit(ImageData fillData, ImageData bgData, ImageData handleData, RECT margin)
{
    fill = D2DImageManager::GetInstance()->AddImage(fillData.keyName, fillData.filePath);

    if (bgData.keyName != "")
    {
        bg = D2DImageManager::GetInstance()->AddImage(bgData.keyName, bgData.filePath);
    }

    if (handleData.keyName != "")
    {
        handleImg = D2DImageManager::GetInstance()->AddImage(handleData.keyName, handleData.filePath);
    }

    this->margin = margin;

	fillRectTransfrom = { rectTransform.left + margin.left, rectTransform.top + margin.top,
		rectTransform.left + (int)(width * fillValue), rectTransform.bottom};
}

void UI::UISlider::UpdateFill()
{
    fillValue = max(0.0f, min((goalValue / maxValue), 1.0f));
}

float UISlider::SmoothDamp(float current, float target, float& velocity, float smoothTime, float deltaTime)
{
    float omega = 2.0f / smoothTime;
    float x = omega * deltaTime;
    float exp = 1.0f / (1.0f + x + 0.48f * x * x + 0.235f * x * x * x);
    float change = current - target;
    float temp = (velocity + omega * change) * deltaTime;
    velocity = (velocity - omega * temp) * exp;
    float output = target + (change + temp) * exp;

    if ((target - current > 0.0f) == (output > target))
    {
        output = target;
        velocity = 0.0f;
    }

    return output;
}

