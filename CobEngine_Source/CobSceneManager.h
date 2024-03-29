#pragma once
#include "CobScene.h"

namespace Cob
{
	/**
	 * \brief ������ ����
	 */
	class SceneManager
	{
	public:
		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC Hdc);

		template <typename T>
		static Scene* CreateScene(const std::wstring& Name)
		{
			T* scene = new T;
			mActiveScene = scene;

			scene->SetName(Name);
			scene->Initialize();


			mScene.insert({Name, scene});
			return scene;
		}

		static Scene* LoadScene(const std::wstring& Name);

		FORCEINLINE static Scene* GetActiveScene() { return mActiveScene; }

	private:
		static std::map<std::wstring, Scene*> mScene;
		static Scene* mActiveScene;
	};
}
