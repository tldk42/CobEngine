#pragma once
#include "CobComponent.h"

namespace Cob
{
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
		                     , Texture* SpriteSheet
		                     , Math::Vector2 LeftTop
		                     , Math::Vector2 Size
		                     , Math::Vector2 Offset
		                     , UINT SpriteLength
		                     , float Duration);
		void PlayAnimation(const std::wstring& Name, bool bLoopAnimation = false);

		class Animation* FindAnimation(const std::wstring& Name);

	private:
		std::map<std::wstring, Animation*> mAnimations;
		Animation* mActiveAnimation;
		bool bLoop;
	};
}
