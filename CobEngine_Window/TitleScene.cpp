#include "TitleScene.h"

#include "CobInput.h"
#include "CobPlayer.h"
#include "CobSceneManager.h"
#include "CobSpriteRenderer.h"
#include "CobTransform.h"


namespace Cob
{
	TitleScene::TitleScene()
	{
	}

	TitleScene::~TitleScene()
	{
	}

	void TitleScene::Initialize()
	{
		{
			Player* bg = new Player();
			Transform* tr
				= bg->AddComponent<Transform>();
			tr->SetPosition({0, 0});

			tr->SetName(L"TR");

			SpriteRenderer* sr
				= bg->AddComponent<SpriteRenderer>();
			sr->SetName(L"SR");
			sr->LoadImage_Implement(L"../Resource/title.png");

			AddGameObject(bg, ELayerType::Background);
		}
	}

	void TitleScene::Update()
	{
		Scene::Update();
	}

	void TitleScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(EKeyCode::N))
		{
			SceneManager::LoadScene(L"PlayScene");
		}
	}

	void TitleScene::Render(HDC Hdc)
	{
		Scene::Render(Hdc);

		wchar_t str[50] = L"Title Scene";
		TextOut(Hdc, 0, 0, str, 11);
	}
}
