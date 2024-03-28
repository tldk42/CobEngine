#pragma once
#include "CobPlayScene.h"
#include "TitleScene.h"

#include "../CobEngine_Source/CobSceneManager.h"

namespace Cob
{
	inline void LoadScenes()
	{
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		SceneManager::CreateScene<TitleScene>(L"TitleScene");

		SceneManager::LoadScene(L"PlayScene");
	}
}
