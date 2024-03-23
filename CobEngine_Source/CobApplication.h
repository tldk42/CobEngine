#pragma once
#include "CobObject.h"

namespace Cob
{
	class Application
	{
	public:
		Application();
		~Application();

		void Initialize(HWND Hwnd, UINT Width, UINT Height);
		void Run();

		void Update();
		void LateUpdate();
		void Render();

	private:
		HWND mHwnd;
		HDC mHdc;

		HDC mBackHdc;
		HBITMAP mBackBitmap;

		UINT mWidth;
		UINT mHeight;

		Object mPlayer;
	};
}
