#pragma once
#include "CommonInclude.h"

namespace Cob
{
	class Engine
	{
	public:
		Engine() = delete;
		Engine(HINSTANCE Hinstance, LPCTSTR WindowClass, LPCTSTR Title, WORD Icon, WORD SmallIcon,
		       int       Width = 640, int   Height = 480);
		~Engine();

		HRESULT Initialize(int CmdShow);
		LRESULT HandleEvent(HWND WindowHandle, UINT Message, WPARAM WParam, LPARAM LParam);
		void    Run();

		FORCEINLINE static Engine* GetEngine() { return s_Engine; }

#pragma region Getter
		FORCEINLINE HINSTANCE GetInstance() const { return mHinstance; }
		FORCEINLINE HWND      GetWindow() const { return mHWindow; }
		FORCEINLINE WORD      GetIcon() const { return mIcon; }
		FORCEINLINE WORD      GetSmallIcon() const { return mSmallIcon; }
		FORCEINLINE LPTSTR    GetTitle() { return mTitle; }
		FORCEINLINE bool      IsPaused() const { return bPaused; }
		FORCEINLINE bool      IsRunning() const { return bRunning; }
		FORCEINLINE int       GetWidth() const { return mWindowWidth; }
		FORCEINLINE int       GetHeight() const { return mWindowHeight; }
		FORCEINLINE int       GetFrameDelay() const { return mFrameDelay; }
#pragma endregion

#pragma region Setter
		FORCEINLINE void SetWindow(const HWND WindowHandle) { mHWindow = WindowHandle; }
		FORCEINLINE void SetFrameRate(const int FrameRate) { mFrameDelay = 1000 / FrameRate; }
		FORCEINLINE void SetSleep(const bool bInValue) { bPaused = bInValue; }
#pragma endregion

	private:
		void Update();

	protected:
		static Engine* s_Engine;

#pragma region Handles
		HINSTANCE mHinstance; // program handle
		HWND      mHWindow; // window handle
		HCURSOR   mHCursor;
#pragma endregion

#pragma region Strings
		TCHAR mTitle[32]; // program title
		TCHAR mWindowClass[32]; // program window class name
#pragma endregion

#pragma region Icon
		WORD mIcon; // app icon
		WORD mSmallIcon; // app small icon
#pragma endregion

#pragma region Window Resolution
		int mWindowWidth;
		int mWindowHeight;
#pragma endregion

		bool bRunning;
		bool bPaused;
		int  mFrameDelay;

		friend LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
	};
}
