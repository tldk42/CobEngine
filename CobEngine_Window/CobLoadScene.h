#pragma once
#include "CobPlayScene.h"
#include "TitleScene.h"

#include "../CobEngine_Source/CobSceneManager.h"

namespace Cob
{
	inline void LoadScenes()
	{
		SceneManager::CreateScene<PlayScene>(L"PackMan Game");
		SceneManager::CreateScene<TitleScene>(L"TitleScene");

		SceneManager::LoadScene(L"PackMan Game");
	}
}
