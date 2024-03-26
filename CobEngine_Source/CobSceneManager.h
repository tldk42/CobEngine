#pragma once
#include <map>

#include "CobScene.h"

namespace Cob
{
	/**
	 * \brief ¾ÀµéÀ» °ü¸®
	 */
	class SceneManager
	{
	public:
		template <typename T>
		static Scene* CreateScene(const std::wstring& Name)
		{
			T* scene = new T();
			scene->SetName(Name);
			scene->Initialize();

			mScene.insert({Name, scene});
			return scene;
		}

		static Scene* LoadScene(const std::wstring& Name)
		{
			const std::map<std::wstring, Scene*>::iterator foundScene = mScene.find(Name);


			if (foundScene == mScene.end())
			{
				return nullptr;
			}

			mActiveScene = foundScene->second;

			return foundScene->second;
		}

		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC Hdc);

	private:
		static std::map<std::wstring, Scene*> mScene;
		static Scene* mActiveScene;
	};
}
