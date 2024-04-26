#include "CobPlayScene.h"

#include "CobAnimator.h"
#include "CobInput.h"
#include "CobPlayer.h"
#include "CobPlayerScript.h"
#include "CobResources.h"
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
		Texture* backgroundTexture = Resources::Find<Texture>(L"Map");
		Texture* pacManTexture     = Resources::Find<Texture>(L"PacMan");

		Object*         background         = Object::Instantiate<Object>(ELayerType::Background);
		SpriteRenderer* backgroundRenderer = background->AddComponent<SpriteRenderer>();
		backgroundRenderer->SetSize({2.f, 2.f});

		Object*         pacMan         = Object::Instantiate<Object>(ELayerType::Player, {100.f, 100.f});
		SpriteRenderer* pacmanRenderer = pacMan->AddComponent<SpriteRenderer>();
		Animator*       pacmanAnimator = pacMan->AddComponent<Animator>();
		pacMan->AddComponent<PlayerScript>();

		backgroundRenderer->SetTexture(backgroundTexture);
		pacmanRenderer->SetTexture(pacManTexture);

		Scene::Initialize();
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

		TextOut(Hdc, 0, 0, L"PackMan Game Scene", 18);
	}

	void PlayScene::OnEnter()
	{
		Scene::OnEnter();
	}

	void PlayScene::OnExit()
	{
		Transform* tr = mPlayer->GetComponent<Transform>();
		tr->SetPosition(Vector2(0, 0));
	}
}
