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
		for (auto& iter : mAnimations)
		{
			delete iter.second;
			iter.second = nullptr;
		}

		for (auto& iter : mEvents)
		{
			delete iter.second;
			iter.second = nullptr;

		}
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

			Events* events = FindEvents(mActiveAnimation->GetName());

			if (mActiveAnimation->IsComplete())
			{
				// �̺�Ʈ ���ε�
				if (events)
				{
					events->OnComplete();

				}
				if (bLoop)
				{
					mActiveAnimation->Reset();
				}
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
	                               const float         Duration)
	{
		if (!FindAnimation(Name))
		{
			Animation* newAnimation = new Animation;
			newAnimation->SetName(Name);
			newAnimation->CreateAnimation(Name, SpriteSheet, LeftTop, Size, Offset, SpriteLength, Duration);

			newAnimation->SetAnimator(this);

			Events* events = new Events();
      
			mEvents.insert({Name, events});

			mAnimations.insert({Name, newAnimation});
		}
	}

	// void Animator::CreateAnimation(const std::wstring& Name, Texture* Sprites[], const float Duration)
	// {
	// 	if (!FindAnimation(Name))
	// 	{
	// 		Animation* newAnimation = new Animation;
	// 		newAnimation->CreateAnimation(Name, Sprites, Duration);
	//
	// 		newAnimation->SetAnimator(this);
	// 		mAnimations.insert({Name, newAnimation});
	// 	}
	// }

	void Animator::PlayAnimation(const std::wstring& Name, const bool bLoopAnimation)
	{
		if (Animation* animationToPlay = FindAnimation(Name))
		{
			if (mActiveAnimation)
			{
				Events* currentEvents = FindEvents(mActiveAnimation->GetName());
				if (currentEvents)
				{
					currentEvents->OnEnd();
				}

				Events* nextEvents = FindEvents(animationToPlay->GetName());
				if (nextEvents)
				{
					nextEvents->OnStart();
				}
			}

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

	Events* Animator::FindEvents(const std::wstring& Name)
	{
		if (mEvents.contains(Name))
		{
			return mEvents[Name];
		}
		return nullptr;
	}

	std::function<void()>& Animator::GetStartEvent(const std::wstring& Name)
	{
		Events* events = FindEvents(Name);
		return events->OnStart.mEvent;

	}

	std::function<void()>& Animator::GetCompleteEvent(const std::wstring& Name)
	{
		Events* events = FindEvents(Name);
		return events->OnComplete.mEvent;

	}

	std::function<void()>& Animator::GetEndEvent(const std::wstring& Name)
	{
		Events* events = FindEvents(Name);
		return events->OnEnd.mEvent;
	}
}
