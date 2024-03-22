#include "CobApplication.h"

namespace Cob
{
	Application::Application()
		: mHwnd(nullptr),
		  mHdc(nullptr)
	{
	}

	Application::~Application()
	{
	}

	void Application::Initialize(HWND hwnd)
	{
		mHwnd = hwnd;

		if (mHwnd)
		{
			mHdc = GetDC(mHwnd);
			mPlayer.SetPosition(0, 0);
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
		mPlayer.Update();
	}

	void Application::LateUpdate()
	{
	}

	void Application::Render()
	{
		mPlayer.Render(mHdc);
	}
}
