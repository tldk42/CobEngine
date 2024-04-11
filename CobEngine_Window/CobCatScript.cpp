#include "CobCatScript.h"

#include "CobAnimator.h"
#include "CobInput.h"
#include "CobObject.h"
#include "CobTime.h"

namespace Cob
{
	CatScript::CatScript()
		: mAnimator(nullptr),
		  mTime(0),
		  mState(ECatState::LayDown),
		  mWalkDirection()
	{
	}

	CatScript::~CatScript()
	{
	}

	void CatScript::Initialize()
	{
		Script::Initialize();
	}

	void CatScript::Update()
	{
		if (!mAnimator)
		{
			mAnimator = GetOwner()->GetComponent<Animator>();
		}

		switch (mState)
		{
		case ECatState::Idle:
			break;
		case ECatState::LayDown:
			SitDown();
			break;
		case ECatState::Walk:
			Move();
			break;
		case ECatState::Attack:
			break;
		case ECatState::SitDown:
			SitDown();
			break;
		}
	}

	void CatScript::LateUpdate()
	{
		Script::LateUpdate();
	}

	void CatScript::Render(HDC Hdc)
	{
		Script::Render(Hdc);
	}

	void CatScript::SitDown()
	{
		mTime += Time::DeltaTime();
		if (mTime > 3.0f)
		{
			mState         = ECatState::Walk;
			int direction  = (rand() % 4);
			mWalkDirection = static_cast<ECatWalkDirection>(direction);
			PlayWalkAnimationByDirection(mWalkDirection);
			mTime = 0.0f;
		}
	}

	void CatScript::Move()
	{
		mTime += Time::DeltaTime();

		if (mTime > 2.f)
		{
			const int bIsLayDown = rand() % 2;

			mState = bIsLayDown ? ECatState::LayDown : ECatState::SitDown;
			mAnimator->PlayAnimation(bIsLayDown ? L"LayDown" : L"SitDown", false);
		}

		Transform* transform = GetOwner()->GetComponent<Transform>();
		Translate(transform);
	}

	void CatScript::LayDown()
	{
	}

	void CatScript::PlayWalkAnimationByDirection(ECatWalkDirection Direction)
	{
		switch (Direction)
		{
		case ECatWalkDirection::Left:
			mAnimator->PlayAnimation(L"LeftWalk", true);
			break;
		case ECatWalkDirection::Right:
			mAnimator->PlayAnimation(L"RightWalk", true);
			break;
		case ECatWalkDirection::Up:
			mAnimator->PlayAnimation(L"UpWalk", true);
			break;
		case ECatWalkDirection::Down:
			mAnimator->PlayAnimation(L"DownWalk", true);
			break;
		case ECatWalkDirection::End:
			break;
		}
	}

	void CatScript::Translate(Transform* Transform)
	{
		Vector2 currentPosition = Transform->GetPosition();

		switch (mWalkDirection)
		{
		case ECatWalkDirection::Left:
			currentPosition.X -= 100.f * Time::DeltaTime();
			break;
		case ECatWalkDirection::Right:
			currentPosition.X += 100.f * Time::DeltaTime();
			break;
		case ECatWalkDirection::Up:
			currentPosition.Y -= 100.f * Time::DeltaTime();
			break;
		case ECatWalkDirection::Down:
			currentPosition.Y += 100.f * Time::DeltaTime();
			break;
		case ECatWalkDirection::End:
			break;
		}

		Transform->SetPosition(currentPosition);
	}
}
