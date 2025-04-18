#include "UITextBox.h"  
#include "UIText.h"  
#include "UIImage.h"
#include "D2DImageManager.h"  
#include "D2DImage.h"

using namespace UI;  

void UITextBox::Init(UIObject* parent, FRECT rect, FPOINT scale, ImageData bgData, FRECT margin)
{  
   UIObject::Init(parent, rect, scale);  

   this->margin = margin;
   ResourceInit(bgData);
}  

void UITextBox::Init(UIObject* parent, int dx, int dy, int width, int height, 
    FPOINT scale, ImageData bgData, FRECT margin)
{  
   UIObject::Init(parent, dx, dy, width, height, scale);  
   this->margin = margin;
   ResourceInit(bgData); 
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

void UI::UITextBox::SetTextStyle(TextStyle txtStyle)
{
    if (textUI)
    {
        textUI->SetTextStyle(txtStyle);
    }
}

void UITextBox::ResourceInit(ImageData bgData)
{  
    textUI = new UIText();
    bg = new UIImage();

    if (bgData.keyName != "")
    {
        bg->Init(this, { 0,0,0,0 }, { 1.0f, 1.0f }, bgData);
    }
   textUI->Init(this, { margin.left, margin.top, 0, 0});
}
