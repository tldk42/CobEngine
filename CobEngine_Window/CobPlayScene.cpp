#include "CobPlayScene.h"

#include "CobPlayer.h"
#include "CobTransform.h"
#include "CobSpriteRenderer.h"

namespace Cob
{
	PlayScene::PlayScene()
	{
	}

	PlayScene::~PlayScene()
	{
	}

	void PlayScene::Initialize()
	{
		// for (size_t i = 0; i < 100; ++i)
		// {
		// 	Object* object = new Object;
		// 	AddGameObject(object);
		// }
		{
			Player* pl = new Player();
			Transform* tr
				= pl->AddComponent<Transform>();
			tr->SetPosition(800, 450);

			tr->SetName(L"TR");

			SpriteRenderer* sr
				= pl->AddComponent<SpriteRenderer>();
			sr->SetName(L"SR");

			AddGameObject(pl);
		}

		{
			Player* pl = new Player();
			Transform* tr
				= pl->AddComponent<Transform>();
			tr->SetPosition(300, 450);

			tr->SetName(L"TR");

			SpriteRenderer* sr
				= pl->AddComponent<SpriteRenderer>();
			sr->SetName(L"SR");

			AddGameObject(pl);
		}

		{
			Player* pl = new Player();
			Transform* tr
				= pl->AddComponent<Transform>();
			tr->SetPosition(100, 650);

			tr->SetName(L"TR");

			SpriteRenderer* sr
				= pl->AddComponent<SpriteRenderer>();
			sr->SetName(L"SR");

			AddGameObject(pl);
		}
	}

	void PlayScene::Update()
	{
		Scene::Update();
	}

	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();
	}

	void PlayScene::Render(HDC Hdc)
	{
		Scene::Render(Hdc);
	}
}
