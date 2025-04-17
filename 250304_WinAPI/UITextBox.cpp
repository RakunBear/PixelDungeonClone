#include "UITextBox.h"  
#include "UIText.h"  
#include "UIImage.h"
#include "D2DImageManager.h"  
#include "D2DImage.h"

using namespace UI;  

void UITextBox::Init(UIObject* parent, FRECT rect, FPOINT scale, const string& text, ImageData bgData, FRECT margin)
{  
   UIObject::Init(parent, rect, scale);  

   this->margin = margin;
   ResourceInit(text, bgData);
}  

void UITextBox::Init(UIObject* parent, int dx, int dy, int width, int height, FPOINT scale, const string& text, ImageData bgData, FRECT margin)
{  
   UIObject::Init(parent, dx, dy, width, height, scale);  

   ResourceInit(text, bgData); 
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
        bg->Render();
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

void UITextBox::ResourceInit(const string& text, ImageData bgData)
{  
    textUI = new UIText();
    bg = new UIImage();

    if (bgData.keyName != "")
    {
        bg->Init(this, { 0,0,0,0 }, { 1.0f, 1.0f }, bgData);
    }
   FPOINT centerPos = GetLocalPos();
   textUI->Init(nullptr, {centerPos.x, centerPos.y,0,0}, text);
   textUI->SetPos(centerPos.x + margin.left, centerPos.y + margin.top);
}
