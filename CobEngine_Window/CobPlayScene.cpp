#include "CobPlayScene.h"

#include "CobAnimator.h"
#include "CobCamera.h"
#include "CobCat.h"
#include "CobCatScript.h"
#include "CobInput.h"
#include "CobPlayer.h"
#include "CobPlayerScript.h"
#include "CobRenderer.h"
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
		Object* camera          = Object::Instantiate<Object>(ELayerType::Particle, Vector2(344.f, 442.f));
		Camera* cameraComponent = camera->AddComponent<Camera>();
		Renderer::mainCamera    = cameraComponent;

		mPlayer = Object::Instantiate<Player>(ELayerType::Particle);
		mPlayer->AddComponent<PlayerScript>();

		// SpriteRenderer* spriteRenderer = mPlayer->AddComponent<SpriteRenderer>();
		// spriteRenderer->SetSize({3.f, 3.f});

		Texture*  packManTexture  = Resources::Find<Texture>(L"Cat");
		Animator* packManAnimator = mPlayer->AddComponent<Animator>();

		packManAnimator->CreateAnimation(L"SitDown", packManTexture
		                                 , Vector2(0.0f, 128.0f), Vector2(32.0f, 32.0f), Vector2::ZERO, 4, 0.1f);
		packManAnimator->CreateAnimation(L"DownWalk", packManTexture
		                                 , Vector2(0.0f, 0.0f), Vector2(32.0f, 32.0f), Vector2::ZERO, 4, 0.1f);
		packManAnimator->CreateAnimation(L"RightWalk", packManTexture
		                                 , Vector2(0.0f, 32.0f), Vector2(32.0f, 32.0f), Vector2::ZERO, 4, 0.1f);
		packManAnimator->CreateAnimation(L"UpWalk", packManTexture
		                                 , Vector2(0.0f, 64.0f), Vector2(32.0f, 32.0f), Vector2::ZERO, 4, 0.1f);
		packManAnimator->CreateAnimation(L"LeftWalk", packManTexture
		                                 , Vector2(0.0f, 96.0f), Vector2(32.0f, 32.0f), Vector2::ZERO, 4, 0.1f);
		packManAnimator->CreateAnimation(L"SitDown", packManTexture
		                                 , Vector2(0.0f, 128.0f), Vector2(32.0f, 32.0f), Vector2::ZERO, 4, 0.1f);
		packManAnimator->CreateAnimation(L"Grooming", packManTexture
		                                 , Vector2(0.0f, 160.0f), Vector2(32.0f, 32.0f), Vector2::ZERO, 4, 0.1f);

		packManAnimator->PlayAnimation(L"SitDown", false);

		mPlayer->GetComponent<Transform>()->SetPosition(Vector2(100.0f, 100.0f));
		mPlayer->GetComponent<Transform>()->SetScale(Vector2(2.0f, 2.0f));

		Cat* cat = Object::Instantiate<Cat>(ELayerType::Animal);
		cat->AddComponent<CatScript>();

		Texture*  catTex      = Resources::Find<Texture>(L"Cat");
		Animator* catAnimator = cat->AddComponent<Animator>();
		catAnimator->CreateAnimation(L"DownWalk", catTex
		                             , Vector2(0.0f, 0.0f), Vector2(32.0f, 32.0f), Vector2::ZERO, 4, 0.1f);
		catAnimator->CreateAnimation(L"RightWalk", catTex
		                             , Vector2(0.0f, 32.0f), Vector2(32.0f, 32.0f), Vector2::ZERO, 4, 0.1f);
		catAnimator->CreateAnimation(L"UpWalk", catTex
		                             , Vector2(0.0f, 64.0f), Vector2(32.0f, 32.0f), Vector2::ZERO, 4, 0.1f);
		catAnimator->CreateAnimation(L"LeftWalk", catTex
		                             , Vector2(0.0f, 96.0f), Vector2(32.0f, 32.0f), Vector2::ZERO, 4, 0.1f);
		catAnimator->CreateAnimation(L"SitDown", catTex
		                             , Vector2(0.0f, 128.0f), Vector2(32.0f, 32.0f), Vector2::ZERO, 4, 0.1f);
		catAnimator->CreateAnimation(L"Grooming", catTex
		                             , Vector2(0.0f, 160.0f), Vector2(32.0f, 32.0f), Vector2::ZERO, 4, 0.1f);
		catAnimator->CreateAnimation(L"LayDown", catTex
		                             , Vector2(0.0f, 192.0f), Vector2(32.0f, 32.0f), Vector2::ZERO, 4, 0.1f);

		catAnimator->PlayAnimation(L"SitDown", false);
		cat->GetComponent<Transform>()->SetPosition(Vector2(200.0f, 200.0f));
		cat->GetComponent<Transform>()->SetScale(Vector2(2.0f, 2.0f));

		Object*         background         = Object::Instantiate<Object>(ELayerType::Player);
		SpriteRenderer* backgroundRenderer = background->AddComponent<SpriteRenderer>();
		backgroundRenderer->SetSize({3.f, 3.f});

		Texture* backgroundTexture = Resources::Find<Texture>(L"Bubble");
		backgroundRenderer->SetTexture(backgroundTexture);

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
		Transform* tr = mPlayer->GetComponent<Transform>();
		tr->SetPosition(Vector2(0, 0));
	}
}
