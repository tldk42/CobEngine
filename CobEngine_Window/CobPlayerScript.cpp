#include "CobPlayerScript.h"

#include "CobAnimator.h"
#include "CobInput.h"
#include "CobObject.h"
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

	void PlayerScript::SitDown()
	{
		if (Input::GetKey(EKeyCode::D))
		{
			mPlayerState = EPlayerState::Walk;
			// mAnimator->PlayAnimation(L"RightWalk", true);
		}
		if (Input::GetKey(EKeyCode::A))
		{
			mPlayerState = EPlayerState::Walk;
			// mAnimator->PlayAnimation(L"LeftWalk", true);
		}
		if (Input::GetKey(EKeyCode::W))
		{
			mPlayerState = EPlayerState::Walk;
			// mAnimator->PlayAnimation(L"UpWalk", true);
		}
		if (Input::GetKey(EKeyCode::S))
		{
			mPlayerState = EPlayerState::Walk;
			// mAnimator->PlayAnimation(L"DownWalk", true);
		}
	}

	void PlayerScript::Move()
	{
		Transform* playerTransform = GetOwner()->GetComponent<Transform>();
		Vector2 playerPosition = playerTransform->GetPosition();

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
			// mPlayerState = EPlayerState::SitDown;
			// mAnimator->PlayAnimation(L"SitDown", false);
		}
	}
}
