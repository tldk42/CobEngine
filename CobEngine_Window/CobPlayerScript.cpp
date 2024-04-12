#include "CobPlayerScript.h"

#include "CobAnimator.h"
#include "CobCat.h"
#include "CobCatScript.h"
#include "CobInput.h"
#include "CobObject.h"
#include "CobResources.h"
#include "CobTime.h"
#include "CobTransform.h"

namespace Cob
{
	PlayerScript::PlayerScript()
		: mAnimator(nullptr),
		  mPlayerState(EPlayerState::SitDown)
	{
	}

	PlayerScript::~PlayerScript()
	{
	}

	void PlayerScript::Initialize()
	{
		Script::Initialize();
	}

	void PlayerScript::Update()
	{
		if (!mAnimator)
		{
			mAnimator = GetOwner()->GetComponent<Animator>();
		}

		switch (mPlayerState)
		{
		case EPlayerState::Sleep:
			break;
		case EPlayerState::SitDown:
			SitDown();
			break;
		case EPlayerState::Walk:
			Move();
			break;
		case EPlayerState::Attack:
			break;
		}
	}

	void PlayerScript::LateUpdate()
	{
	}

	void PlayerScript::Render(HDC Hdc)
	{
	}

	void PlayerScript::AttackEffect()
	{
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
	}

	void PlayerScript::SitDown()
	{
		if (Input::GetKey(EKeyCode::D))
		{
			mPlayerState = EPlayerState::Walk;
			mAnimator->PlayAnimation(L"RightWalk", true);
		}
		if (Input::GetKey(EKeyCode::A))
		{
			mPlayerState = EPlayerState::Walk;
			mAnimator->PlayAnimation(L"LeftWalk", true);
		}
		if (Input::GetKey(EKeyCode::W))
		{
			mPlayerState = EPlayerState::Walk;
			mAnimator->PlayAnimation(L"UpWalk", true);
		}
		if (Input::GetKey(EKeyCode::S))
		{
			mPlayerState = EPlayerState::Walk;
			mAnimator->PlayAnimation(L"DownWalk", true);
		}
	}

	void PlayerScript::Move()
	{
		Transform* playerTransform = GetOwner()->GetComponent<Transform>();
		Vector2    playerPosition  = playerTransform->GetPosition();

		if (Input::GetKey(EKeyCode::D))
		{
			playerPosition.X += 100.f * Time::DeltaTime();
		}
		if (Input::GetKey(EKeyCode::A))
		{
			playerPosition.X -= 100.f * Time::DeltaTime();
		}
		if (Input::GetKey(EKeyCode::W))
		{
			playerPosition.Y -= 100.f * Time::DeltaTime();
		}
		if (Input::GetKey(EKeyCode::S))
		{
			playerPosition.Y += 100.f * Time::DeltaTime();
		}

		playerTransform->SetPosition(playerPosition);

		if (Input::GetKeyUp(EKeyCode::D)
			|| Input::GetKeyUp(EKeyCode::A)
			|| Input::GetKeyUp(EKeyCode::W)
			|| Input::GetKeyUp(EKeyCode::S))
		{
			mPlayerState = EPlayerState::SitDown;
			mAnimator->PlayAnimation(L"SitDown", false);
		}
	}
}
