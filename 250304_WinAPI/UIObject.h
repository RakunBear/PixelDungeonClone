#pragma once
#include "config.h"
#include <xkeycheck.h>

namespace UI
{
	struct Transform
	{
		FRECT transform{ 0.0f,0.0f,0.0f,0.0f };
		FPOINT scale{ 1.0f,1.0f };

		FRECT zero() { return { 0.0f, 0.0f, 0.0f, 0.0f }; }
	};

	struct ImageData
	{
		const char* keyName;
		const wchar_t* filePath;
		bool isTransparent{ false };
		COLORREF transColor{ RGB(0,0,0) };
	};

	struct StatInfo
	{
		int HP;
		int MaxHP;
		int Exp;
		int MaxExp;
		int Level;
	};

	class UIObject
	{
	public:
		UIObject() = default;
		virtual ~UIObject() = default;

		virtual void Init(UIObject* parent, FRECT relativeRect = {0.0f,0.0f,0.0f,0.0f}, FPOINT scale = {1.0f, 1.0f});
		virtual void Init(UIObject* parent = nullptr, int dx = 0, int dy = 0, int width = 0, int height = 0, FPOINT scale = { 1.0f, 1.0f });
		virtual void Release() = 0;
		virtual void Update() = 0;
		virtual void Render() = 0;

		void SetParent(UIObject* parent);
		virtual void SetPos(float dx, float dy);
		void SetScale(FPOINT scale);
		void SetSize(int w, int h);
		void SetRect(FRECT rect);

		inline POINT GetSize()
		{
			int width = (this->localTransform.transform.right - this->localTransform.transform.left);
			width = width * this->worldTransform.scale.x;
			int height = (this->localTransform.transform.bottom - this->localTransform.transform.top);
			height = height * this->worldTransform.scale.y;

			return { width, height };
		}
		inline FPOINT GetLocalPos()
		{
			float centerX = (this->localTransform.transform.left + this->localTransform.transform.right) / 2.0f;
			float centerY = (this->localTransform.transform.top + this->localTransform.transform.bottom) / 2.0f;
			
			return { centerX, centerY };
		}
		inline FPOINT GetWorldPos()
		{
			float centerX = (this->worldTransform.transform.left + this->worldTransform.transform.right) / 2.0f;
			float centerY = (this->worldTransform.transform.top + this->worldTransform.transform.bottom) / 2.0f;

			return { centerX, centerY };
		}

	protected:
		void UpdateWorldTransform();

	public:
		bool isVisible{ true };
	protected:
		UIObject* parent{ nullptr };
		Transform localTransform;
		Transform worldTransform;
	};

}