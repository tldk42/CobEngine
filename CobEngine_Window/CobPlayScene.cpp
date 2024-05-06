#include "CobPlayScene.h"

#include "CobAnimator.h"
#include "CobInput.h"
#include "CobPlayer.h"
#include "CobPlayerScript.h"
#include "CobResources.h"
#include "CobSceneManager.h"
#include "CobTransform.h"
#include "CobSpriteRenderer.h"
#include "CobCollisionManager.h"
#include "BoxCollider2D.h"

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
		CollisionManager::CollisionLayerCheck(ELayerType::Player, ELayerType::Animal, true);
		CollisionManager::CollisionLayerCheck(ELayerType::Player, ELayerType::Background, true);

		Texture* backgroundTexture = Resources::Find<Texture>(L"Map");
		Texture* pacManTexture     = Resources::Find<Texture>(L"PacMan");
		Texture* ghostTexture      = Resources::Find<Texture>(L"Ghost");

		Object*         background         = Object::Instantiate<Object>(ELayerType::Background, {0.f, 0.f});
		SpriteRenderer* backgroundRenderer = background->AddComponent<SpriteRenderer>();


		backgroundRenderer->SetSize({2.f, 2.f});

		Object* backgroundCollider_Top = Object::Instantiate<Object>(ELayerType::Background, {0, 0});
		backgroundCollider_Top->AddComponent<BoxCollider2D>()->SetSize({450.f, 5.f});
		Object* backgroundCollider_Left = Object::Instantiate<Object>(ELayerType::Background, {0, 5.f});
		backgroundCollider_Left->AddComponent<BoxCollider2D>()->SetSize({5.f, 530.f});
		Object* backgroundCollider_Bottom = Object::Instantiate<Object>(ELayerType::Background, {0, 540});
		backgroundCollider_Bottom->AddComponent<BoxCollider2D>()->SetSize({450.f, 5.f});
		Object* backgroundCollider_Right = Object::Instantiate<Object>(ELayerType::Background, {440, 5.f});
		backgroundCollider_Right->AddComponent<BoxCollider2D>()->SetSize({5.f, 530.f});

		mPlayer         = Object::Instantiate<Player>(ELayerType::Player, {100.f, 100.f});
		SpriteRenderer* pacmanRenderer = mPlayer->AddComponent<SpriteRenderer>();
		// Animator*       pacmanAnimator = pacMan->AddComponent<Animator>();
		Object::DontDestroyOnLoad(mPlayer);

		PlayerScript* pacManScript = mPlayer->AddComponent<PlayerScript>();

		if (BoxCollider2D* pacManBoxCollider = mPlayer->AddComponent<BoxCollider2D>())
		{
			pacManBoxCollider->SetInitValue({-3.f, -3.f}, {20.f, 20.f});
		}

		Object*         ghost1         = Object::Instantiate<Object>(ELayerType::Animal, {150, 150.f});
		SpriteRenderer* ghost1Renderer = ghost1->AddComponent<SpriteRenderer>();
		// Animator*       ghost1Animator = ghost1->AddComponent<Animator>();

		// Add ghost(monster) Script
		Script* ghost1Script = ghost1->AddComponent<Script>();

		if (BoxCollider2D* ghost1BoxCollider = ghost1->AddComponent<BoxCollider2D>())
		{
			ghost1BoxCollider->SetInitValue({-5.f, -5.f}, {25.f, 25.f});
			ghost1BoxCollider->SetDebugColor(RGB(234, 12, 12));
		}

		if (backgroundRenderer && backgroundTexture)
		{
			backgroundRenderer->SetTexture(backgroundTexture);
		}
		if (pacmanRenderer && pacManTexture)
		{
			pacmanRenderer->SetTexture(pacManTexture);
		}
		if (ghost1Renderer && ghostTexture)
		{
			ghost1Renderer->SetTexture(ghostTexture);
		}

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

		TextOut(Hdc, 0, 0, L"PackMan", 7);
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
