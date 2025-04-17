#include "UISlider.h"
#include "D2DImage.h"
#include "D2DImageManager.h"

using namespace UI;

void UI::UISlider::Init(UIObject* parent, FRECT rect, FPOINT scale,
    ImageData imgData, ImageData bgData, ImageData handleData, FRECT margin)
{
    UIObject::Init(parent, rect, scale);
    this->margin = margin;

    ResourceInit(imgData, bgData, handleData);
}

void UISlider::Init(UIObject* parent, int dx, int dy, int width, int height, FPOINT scale,
    ImageData imgData, ImageData bgData, ImageData handleData, FRECT margin)
{
    UIObject::Init(parent, dx, dy, width, height, scale);
    this->margin = margin;

    ResourceInit(imgData, bgData, handleData);
}

void UISlider::Release()
{
    if (fill)
    {
        fill->Release();
        delete fill;
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
        bg->RenderFrameScale(worldTransform.transform.left, worldTransform.transform.top, worldTransform.scale.x, worldTransform.scale.y, 0, 0);
    }
    if (fill)
    {
        fill->RenderPercent(fillFPoint, 0.0f, fillValue * 100.0f, worldTransform.scale.x, worldTransform.scale.y);
    }
    if (handleImg)
    {
        //handleImg->Render(worldTransform.transform.right, worldTransform.transform.top);
    }
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

void UI::UISlider::SetPos(float dx, float dy)
{
    UIObject::SetPos(dx, dy);
    fillFPoint = { worldTransform.transform.left + margin.left, worldTransform.transform.top + margin.top };
}

void UISlider::ResourceInit(ImageData fillData, ImageData bgData, ImageData handleData)
{
    if (fillData.keyName != "")
    {
        fill = D2DImageManager::GetInstance()->CreateImage(fillData.filePath);
        fillFPoint = { worldTransform.transform.left + margin.left, worldTransform.transform.top + margin.top };
    }
    if (bgData.keyName != "")
    {
        bg = D2DImageManager::GetInstance()->AddImage(bgData.keyName, bgData.filePath);
    }

    if (handleData.keyName != "")
    {
        handleImg = D2DImageManager::GetInstance()->AddImage(handleData.keyName, handleData.filePath);
    }
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

