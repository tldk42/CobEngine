#pragma once
#include "CobResource.h"

namespace Cob
{
	class Texture;

	/**
	 * \brief 2D 스프라이트 정보
	 */
	struct Sprite
	{
		/** 이미지에서 좌측 상단의 위치 이미지의 출발점 */
		Math::Vector2 LeftTop;
		/** 스프라이트의 크기 */
		Math::Vector2 Size;
		/** 그 좌상단으로부터의 거리 */
		Math::Vector2 Offset;
		/* 스프라이트 애니메이션 진행 시간 */
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

		/** 타이머, 스프라이트 텍스처 초기화 */
		void Reset();

		/** 애니메이션이 완전 종료되었는지 여부 */
		FORCEINLINE bool IsComplete() const { return bComplete; }
		/** 새로운 애니메이터를 할당 */
		FORCEINLINE void SetAnimator(class Animator* InAnimator) { mAnimator = InAnimator; }

	private:
		/** 이 애니메이션을 실행할 애니메이터 개체 */
		Animator* mAnimator;
		/** 애니메이션을 실행할 스프라이트 배열 */
		std::vector<Sprite> mAnimationSheet;
		/** 현재 스프라이트 텍스처 */
		Texture* mTexture;

		/** 현재 스프라이트 인덱스 */
		int mIndex;
		/** 현재 경과 시간 */
		float mTime;
		/** 애니메이션 1루프 경과여부 */
		bool bComplete;
	};
}
