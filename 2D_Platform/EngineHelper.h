#pragma once
#include "CommonInclude.h"

class EngineHelper
{
public:
	EngineHelper()  = delete;
	~EngineHelper() = delete;

	static void ShowErrorMessageBox(HWND WindowHandle, bool bQuit);
};
