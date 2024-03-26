#pragma once
#include "CobPlayScene.h"

#include "../CobEngine_Source/CobSceneManager.h"

namespace Cob
{
	inline void LoadScenes()
	{
		SceneManager::CreateScene<PlayScene>(L"PlayScene");

		SceneManager::LoadScene(L"PlayScene");
	}
}
