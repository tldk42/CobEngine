#include "CobPlayScene.h"

#include "CobAnimator.h"
#include "CobCamera.h"
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
		Object* camera = Object::Instantiate<Object>(ELayerType::None, Vector2(344.f, 442.f));
		Camera* cameraComponent = camera->AddComponent<Camera>();
		Renderer::mainCamera = cameraComponent;

		mPlayer = Object::Instantiate<Player>(ELayerType::Player);
		mPlayer->AddComponent<PlayerScript>();

		// SpriteRenderer* spriteRenderer = mPlayer->AddComponent<SpriteRenderer>();
		// spriteRenderer->SetSize({3.f, 3.f});

		Texture* packManTexture = Resources::Find<Texture>(L"Cat");
		Animator* packManAnimator = mPlayer->AddComponent<Animator>();
		packManAnimator->CreateAnimation(L"CatFrontMove", packManTexture, {0.f, 0.f}, {32.f, 32.f}, Vector2::ZERO, 4,
		                                 .5f);

		packManAnimator->PlayAnimation(L"CatFrontMove", true);

		Object* background = Object::Instantiate<Object>(ELayerType::Background);
		SpriteRenderer* backgroundRenderer = background->AddComponent<SpriteRenderer>();
		backgroundRenderer->SetSize({3.f, 3.f});

		Texture* backgroundTexture = Resources::Find<Texture>(L"Map");
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
