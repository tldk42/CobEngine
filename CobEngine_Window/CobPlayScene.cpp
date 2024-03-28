#include "CobPlayScene.h"

#include "CobInput.h"
#include "CobPlayer.h"
#include "CobSceneManager.h"
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
		mBackground = Object::Instantiate<Player>(ELayerType::Background, {100.f, 100.f});

		SpriteRenderer* sr = mBackground->AddComponent<SpriteRenderer>();
		sr->LoadImage_Implement(L"../Resource/sample.png");

		Scene::Initialize();
	}

	void PlayScene::Update()
	{
		Scene::Update();
	}

	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(EKeyCode::N))
		{
			SceneManager::LoadScene(L"TitleScene");
		}
	}

	void PlayScene::Render(HDC Hdc)
	{
		Scene::Render(Hdc);

		wchar_t str[50] = L"Play Scene";
		TextOut(Hdc, 0, 0, str, 10);
	}

	void PlayScene::OnEnter()
	{
		Scene::OnEnter();
	}

	void PlayScene::OnExit()
	{
		Transform* tr = mBackground->GetComponent<Transform>();
		tr->SetPosition(Vector2(0, 0));
	}
}
