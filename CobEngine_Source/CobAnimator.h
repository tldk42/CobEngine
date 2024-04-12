#pragma once
#include "CobAnimation.h"
#include "CobComponent.h"

namespace Cob
{
	namespace Anim
	{
		/** 이벤트 */
		struct Event
		{
			/** 이벤트 등록 */
			void operator=(const std::function<void()>& Function)
			{
				mEvent = Function;
			}

			/** 이벤트 실행 */
			void operator()()
			{
				if (mEvent)
				{
					mEvent;
				}
			}

			std::function<void()> mEvent;
		};

		struct Events
		{
			Event StartEvent;
			Event CompleteEvent;
			Event EndEvent;
		};
	}

	using namespace Anim;

	class Texture;

	class Animator : public Component
	{
	public:
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
		void PlayAnimation(const std::wstring& Name, bool bLoopAnimation = false);

		class Animation* FindAnimation(const std::wstring& Name);

		Events*                FindEvents(const std::wstring& Name);
		std::function<void()>& GetStartEvent(const std::wstring& Name);
		std::function<void()>& GetCompleteEvent(const std::wstring& Name);
		std::function<void()>& GetEndEvent(const std::wstring& Name);

		FORCEINLINE bool IsComplete() const { return mActiveAnimation->IsComplete(); }

	private:
		std::map<std::wstring, Animation*> mAnimations;
		std::map<std::wstring, Events*>    mEvents;
		Animation*                         mActiveAnimation;
		bool                               bLoop;
	};
}
