#include "CobApplication.h"
#include "CobInput.h"
#include "CobTime.h"

namespace Cob
{
	Application::Application()
		: mHwnd(nullptr),
		  mHdc(nullptr),
		  mBackHdc(nullptr),
		  mBackBitmap(nullptr),
		  mWidth(0),
		  mHeight(0)
	{
	}

	Application::~Application()
	{
	}

	void Application::Initialize(HWND Hwnd, UINT Width, UINT Height)
	{
		mHwnd = Hwnd;

		if (mHwnd)
		{
			mHdc = GetDC(mHwnd);
			mPlayer.SetPosition(Width / 2, Height / 2);

			RECT rect = {0, 0, Width, Height};
			AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

			mWidth = rect.right - rect.left;
			mHeight = rect.bottom - rect.top;

			SetWindowPos(mHwnd, nullptr, 0, 0, mWidth, mHeight, 0);
			ShowWindow(mHwnd, true);

			mBackBitmap = CreateCompatibleBitmap(mHdc, Width, Height);

			mBackHdc = CreateCompatibleDC(mHdc);

			HBITMAP oldBitmap = static_cast<HBITMAP>(SelectObject(mBackHdc, mBackBitmap));
			DeleteObject(oldBitmap);

			mPlayer.SetPosition(0, 0);

			Input::Initialize();
			Time::Initialize();
		}
	}

	void Application::Run()
	{
		Update();
		LateUpdate();

		Render();
	}

	void Application::Update()
	{
		Input::Update();
		Time::Update();

		mPlayer.Update();
	}

	void Application::LateUpdate()
	{
	}

	void Application::Render()
	{
		Rectangle(mBackHdc, 0, 0, 1600, 900);

		Time::Render(mBackHdc);
		mPlayer.Render(mBackHdc);

		BitBlt(mHdc, 0, 0, mWidth, mHeight, mBackHdc, 0, 0, SRCCOPY);
	}
}
