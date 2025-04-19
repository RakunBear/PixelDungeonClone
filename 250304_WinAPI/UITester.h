#pragma once

namespace UI
{
	class UITester
	{
	public:
		void Init();
		void Release();
		void Update();
		void Render();

		void Reset();

	protected:
		void ResourceInit();

	protected:
	};

}