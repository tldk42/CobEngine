#pragma once
#include "CobResource.h"

namespace Cob
{
	class Texture;

	struct Sprite
	{
		Math::Vector2 LeftTop;
		Math::Vector2 Size;
		Math::Vector2 Offset;
		float Duration;
	};

	class Animation : public Resource
	{
	public:
		Animation();
		~Animation();

		HRESULT Load(const std::wstring& Path) override;

		void Update();
		void Render(HDC Hdc);

		void CreateAnimation(const std::wstring& Name,
		                     Texture* SpriteSheet,
		                     const Math::Vector2& LeftTop,
		                     const Math::Vector2& Size,
		                     const Math::Vector2& Offset,
		                     const UINT SpriteLength,
		                     const float Duration);

		void Reset();

		FORCEINLINE bool IsComplete() const { return bComplete; }
		FORCEINLINE void SetAnimator(class Animator* InAnimator) { mAnimator = InAnimator; }

	private:
		Animator* mAnimator;
		std::vector<Sprite> mAnimationSheet;
		Texture* mTexture;

		int mIndex;
		float mTime;
		bool bComplete;
	};
}
