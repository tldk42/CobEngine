#include "CobSceneManager.h"

namespace Cob
{
	std::map<std::wstring, Scene*> SceneManager::mScene       = {};
	Scene*                         SceneManager::mActiveScene = nullptr;

	void SceneManager::Initialize()
	{
	}

	void SceneManager::Update()
	{
		mActiveScene->Update();
	}

	void SceneManager::LateUpdate()
	{
		mActiveScene->LateUpdate();
	}

	void SceneManager::Render(HDC Hdc)
	{
		mActiveScene->Render(Hdc);
	}

	void SceneManager::Destroy()
	{
		mActiveScene->Destroy();
	}

	void SceneManager::Release()
	{
		for (auto& iter : mScene)
		{
			delete iter.second;
			iter.second = nullptr;
		}
	}

	Scene* SceneManager::CreateScene(const std::wstring& SceneName)
	{
		Scene* scene = new Scene;
		mActiveScene = scene;

		scene->SetName(SceneName);
		scene->Initialize();


		mScene.insert({SceneName, scene});
		return scene;
	}

	Scene* SceneManager::LoadScene(const std::wstring& Name)
	{
		if (mActiveScene)
		{
			mActiveScene->OnExit();
		}

		if (mScene.contains(Name))
		{
			mActiveScene = mScene[Name];
			mActiveScene->OnEnter();

			return mActiveScene;
		}

		return nullptr;
	}
}
