#pragma once
#include <functional>

#include "CobAnimation.h"
#include "CobComponent.h"

namespace Cob
{
	namespace Anim
	{
		struct Event
		{
			void operator=(std::function<void()> func)
			{
				mEvent = std::move(func);
			}

			void operator()()
			{
				if (mEvent)
					mEvent();
			}

			std::function<void()> mEvent;
		};

		struct Events
		{
			Event OnStart;
			Event OnComplete;
			Event OnEnd;
		};
	}

	using namespace Anim;

	class Texture;

	class Animator : public Component
	{
	public:
		struct A
		{
			std::function<void()> mEvents;
		};

		Animator();
		~Animator();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC Hdc) override;

		void CreateAnimation(const std::wstring& Name
		                     , Texture*          SpriteSheet
		                     , Math::Vector2     LeftTop
		                     , Math::Vector2     Size
		                     , Math::Vector2     Offset
		                     , UINT              SpriteLength
		                     , float             Duration);
		void             PlayAnimation(const std::wstring& Name, bool bLoopAnimation = false);
		class Animation* FindAnimation(const std::wstring& Name);

		Events*                FindEvents(const std::wstring& Name);
		std::function<void()>& GetStartEvent(const std::wstring& Name);
		std::function<void()>& GetCompleteEvent(const std::wstring& Name);
		std::function<void()>& GetEndEvent(const std::wstring& Name);

		bool IsComplete() const { return mActiveAnimation->IsComplete(); }

	private:
		std::map<std::wstring, Animation*> mAnimations;
		Animation*                         mActiveAnimation;
		bool                               bLoop;

		std::map<std::wstring, Events*> mEvents;
	};
}
