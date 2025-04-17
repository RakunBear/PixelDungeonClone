#include "UITextBox.h"  
#include "UIText.h"  
#include "D2DImageManager.h"  
#include "D2DImage.h"

using namespace UI;  

void UITextBox::Init(UIObject* parent, RECT rect, const string& text, ImageData bgData, RECT margin)
{  
   UIObject::Init(parent, rect);  

   ResourceInit(text, bgData, margin);
}  

void UITextBox::Init(UIObject* parent, int dx, int dy, int width, int height, const string& text, ImageData bgData, RECT margin)
{  
   UIObject::Init(parent, dx, dy, width, height);  

   ResourceInit(text, bgData, margin); 
}  

void UITextBox::Release()  
{  
   if (textUI)  
   {  
       textUI->Release();  
       delete textUI;  
       textUI = nullptr;  
   }  

   if (bg)  
   {  
       bg = nullptr;  
   }  
}  

void UITextBox::Update()  
{  
}  

void UITextBox::Render()  
{  
    if (bg)
    {
        bg->RenderFrameScale(rectTransform.left, rectTransform.top, 1.0f, 1.0f, 0, 0);
    }

   if (textUI)  
   {  
       textUI->Render();  
   }  
}  

void UITextBox::SetText(const string& text)  
{  
   if (textUI)  
   {  
       textUI->SetText(text);  
   }  
}  

void UITextBox::ResourceInit(const string& text, ImageData bgData, RECT margin)
{  
    if (bgData.keyName != "")
    {
        bg = D2DImageManager::GetInstance()->AddImage(bgData.keyName, bgData.filePath);
    }
   textUI = new UIText();  
   textUI->Init(nullptr, rectTransform, text);  
   textUI->SetPos(centerX + margin.left, centerY + margin.top);
}
