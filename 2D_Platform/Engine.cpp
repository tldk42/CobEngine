#include "Engine.h"

#include "EngineHelper.h"

namespace Cob
{
	Engine* Engine::s_Engine = nullptr;

	LRESULT CALLBACK WndProc(HWND HWnd, UINT Message, WPARAM WParam, LPARAM LParam)
	{
		return Engine::GetEngine()->HandleEvent(HWnd, Message, WParam, LParam);
	}

	Engine::Engine(HINSTANCE Hinstance, LPCTSTR WindowClass, LPCTSTR Title, WORD Icon, WORD SmallIcon, int Width,
	               int       Height)
		: mHinstance(Hinstance),
		  mHWindow(nullptr),
		  mHCursor(nullptr),
		  mIcon(Icon),
		  mSmallIcon(SmallIcon),
		  mWindowWidth(Width),
		  mWindowHeight(Height),
		  bPaused(false),
		  mFrameDelay(50)
	{
		s_Engine = this;

		if (lstrlen(WindowClass) > 0)
		{
			lstrcpy(mWindowClass, WindowClass);
		}
		if (lstrlen(Title) > 0)
		{
			lstrcpy(mTitle, Title);
		}
	}

	Engine::~Engine() {}

	HRESULT Engine::Initialize(int CmdShow)
	{
		HRESULT    InitResult;
		WNDCLASSEX windowClass{};

		windowClass.cbSize        = sizeof(windowClass);
		windowClass.cbClsExtra    = 0;
		windowClass.cbWndExtra    = 0;
		windowClass.hInstance     = mHinstance;
		windowClass.style         = CS_HREDRAW | CS_VREDRAW;
		windowClass.lpfnWndProc   = WndProc;
		windowClass.lpszClassName = mWindowClass;
		windowClass.hCursor       = LoadCursor(nullptr, IDC_ARROW);
		windowClass.hIcon         = LoadIcon(mHinstance, MAKEINTRESOURCE(GetIcon()));
		windowClass.hIconSm       = LoadIcon(mHinstance, MAKEINTRESOURCE(GetSmallIcon()));

		InitResult = RegisterClassEx(&windowClass);

		if (SUCCEEDED(InitResult))
		{
			const int windowWidth  = mWindowWidth + GetSystemMetrics(SM_CXFIXEDFRAME) * 2;
			int       windowHeight = mWindowHeight + GetSystemMetrics(SM_CYFIXEDFRAME) * 2 +
				GetSystemMetrics(SM_CYCAPTION);

			if (windowClass.lpszMenuName != nullptr)
				windowHeight += GetSystemMetrics(SM_CYMENU);
			const int xWindowPos = (GetSystemMetrics(SM_CXSCREEN) - windowWidth) / 2;
			const int yWindowPos = (GetSystemMetrics(SM_CYSCREEN) - windowHeight) / 2;

			mHWindow = CreateWindowEx(WS_EX_APPWINDOW | WS_EX_WINDOWEDGE, mWindowClass, mTitle,
			                          WS_POPUPWINDOW | WS_CAPTION | WS_MINIMIZEBOX,
			                          xWindowPos, yWindowPos, windowWidth, windowHeight,
			                          NULL, NULL, mHinstance, NULL);


			if (!mHWindow)
			{
				EngineHelper::ShowErrorMessageBox(nullptr, false);
				return FALSE;
			}

			bRunning = true;

			ShowWindow(mHWindow, CmdShow);
			UpdateWindow(mHWindow);
		}

		return InitResult;
	}

	LRESULT Engine::HandleEvent(HWND WindowHandle, UINT Message, WPARAM WParam, LPARAM LParam)
	{
		switch (Message)
		{
		case WM_CREATE:
			SetWindow(WindowHandle);
			return 0;
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
		default:
			return DefWindowProc(WindowHandle, Message, WParam, LParam);
		}
	}

	void Engine::Run()
	{
		while (bRunning)
		{
			Update();
		}
	}

	void Engine::Update()
	{
		MSG message;

		while (PeekMessage(&message, nullptr, 0, 0, PM_REMOVE) > 0)
		{
			if (message.message == WM_QUIT)
			{
				bRunning = false;
				return;
			}

			TranslateMessage(&message); // 키보드 입력 메시지를 문자 입력 메시지로 변환
			DispatchMessage(&message); // 메시지 큐에서 꺼낸 메시지를 프로그램의 메시지 처리 함수(WndProc)로 전달
		}
	}
}
