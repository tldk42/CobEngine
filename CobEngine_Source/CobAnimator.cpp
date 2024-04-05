#include "CobAnimator.h"

#include "CobAnimation.h"

namespace Cob
{
	Animator::Animator()
		: Component(EComponentType::Animator),
		  mActiveAnimation(nullptr),
		  bLoop(false)
	{
	}

	Animator::~Animator()
	{
	}

	void Animator::Initialize()
	{
		Component::Initialize();
	}

	void Animator::Update()
	{
		if (mActiveAnimation)
		{
			mActiveAnimation->Update();

			if (mActiveAnimation->IsComplete() && bLoop)
			{
				mActiveAnimation->Reset();
			}
		}
	}

	void Animator::LateUpdate()
	{
		Component::LateUpdate();
	}

	void Animator::Render(HDC Hdc)
	{
		if (mActiveAnimation)
		{
			mActiveAnimation->Render(Hdc);
		}
	}

	void Animator::CreateAnimation(const std::wstring& Name, Texture* SpriteSheet, const Math::Vector2 LeftTop,
	                               const Math::Vector2 Size, const Math::Vector2 Offset, const UINT SpriteLength,
	                               const float Duration)
	{
		if (!FindAnimation(Name))
		{
			Animation* newAnimation = new Animation;
			newAnimation->CreateAnimation(Name, SpriteSheet, LeftTop, Size, Offset, SpriteLength, Duration);

			newAnimation->SetAnimator(this);

			mAnimations.insert({Name, newAnimation});
		}
	}

	void Animator::PlayAnimation(const std::wstring& Name, const bool bLoopAnimation)
	{
		if (Animation* animationToPlay = FindAnimation(Name))
		{
			mActiveAnimation = animationToPlay;
			mActiveAnimation->Reset();
			bLoop = bLoopAnimation;
		}
	}

	Animation* Animator::FindAnimation(const std::wstring& Name)
	{
		if (mAnimations.contains(Name))
		{
			return mAnimations[Name];
		}
		return nullptr;
	}
}
