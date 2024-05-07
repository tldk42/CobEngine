#include "EngineHelper.h"

void EngineHelper::ShowErrorMessageBox(HWND WindowHandle, bool bQuit)
{
	LPVOID lpMsgBuf = nullptr;

	FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
		NULL, GetLastError(), 0,
		(LPTSTR)&lpMsgBuf, 0, NULL);

	MessageBox(WindowHandle, (LPCTSTR)lpMsgBuf, TEXT("Error"), MB_OK | MB_ICONERROR);

	LocalFree(lpMsgBuf); // 메모리 해제

	if (bQuit)
	{
		PostQuitMessage(GetLastError());
	}
}
