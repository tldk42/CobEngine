#include "CobApplication.h"
#include "CobInput.h"
#include "CobSceneManager.h"
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
		AdjustWindowRect_Implement(Hwnd, Width, Height);
		CreateBuffer(Width, Height);
		InitializeEtc();

		SceneManager::Initialize();
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

		SceneManager::Update();
	}

	void Application::LateUpdate()
	{
	}

	void Application::Render()
	{
		ClearRenderTarget();

		Time::Render(mBackHdc);
		SceneManager::Render(mBackHdc);

		BitBlt(mHdc, 0, 0, mWidth, mHeight, mBackHdc, 0, 0, SRCCOPY);
	}

	void Application::ClearRenderTarget()
	{
		Rectangle(mBackHdc, -1, -1, 1601, 901);
	}

	void Application::CopyRenderTarget(HDC Source, HDC Dest)
	{
		// Source(BackBuffer) |> Dest(FrontBuffer)�� �̹����� ����
		// BitBlt API (https://learn.microsoft.com/ko-kr/windows/win32/api/wingdi/nf-wingdi-bitblt)
		BitBlt(Dest, 0, 0, mWidth, mHeight, Source, 0, 0,SRCCOPY);
	}

	void Application::AdjustWindowRect_Implement(HWND Hwnd, UINT Width, UINT Height)
	{
		mHwnd = Hwnd;

		if (mHwnd)
		{
			mHdc = GetDC(mHwnd);

			RECT rect = {0, 0, Width, Height};
			AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

			mWidth = rect.right - rect.left;
			mHeight = rect.bottom - rect.top;

			SetWindowPos(mHwnd, nullptr, 0, 0, mWidth, mHeight, 0);
			ShowWindow(mHwnd, true);
		}
	}

	void Application::CreateBuffer(UINT Width, UINT Height)
	{
		// ���� DeviceContext�� ȣȯ�Ǵ� Bitmap�� ��� �����Ѵ�.
		mBackBitmap = CreateCompatibleBitmap(mHdc, Width, Height);
		mBackHdc = CreateCompatibleDC(mHdc);

		// ��� ������ �����DC�� ����ۺ�Ʈ���� ���� 
		HBITMAP oldBitmap = static_cast<HBITMAP>(SelectObject(mBackHdc, mBackBitmap));
		DeleteObject(oldBitmap);
	}

	void Application::InitializeEtc()
	{
		Input::Initialize();
		Time::Initialize();
	}
}
