#pragma once
#include "config.h"

class D2DImage;
class UI_TestScene
{
private:
	D2DImage* backGround;
public:
	virtual HRESULT Init() ;
	virtual void Release() ;
	virtual void Update() ;
	virtual void Render() ;
};

