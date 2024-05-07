#include "Engine.h"
#include "resource.h"

using namespace Cob;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
	Engine* gameEngine = new Engine(hInstance, TEXT("Win API Sample"), TEXT("Sample Game"), NULL, NULL,
	                                900, 670);

	if (gameEngine)
	{
		if (SUCCEEDED(gameEngine->Initialize(iCmdShow)))
		{
			gameEngine->SetFrameRate(60);

			gameEngine->Run();
		}
	}

	delete gameEngine;
}
