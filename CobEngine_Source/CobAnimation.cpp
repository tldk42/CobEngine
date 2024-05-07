#include "CobAnimation.h"

#include "CobAnimator.h"
#include "CobObject.h"
#include "CobRenderer.h"
#include "CobTexture.h"
#include "CobTime.h"

namespace Cob
{
	Animation::Animation()
		: Resource(EResourceType::Animation),
		  mAnimator(nullptr),
		  mTexture(nullptr),
		  mIndex(-1),
		  mTime(0),
		  bComplete(false)
	{
	}

	Animation::~Animation()
	{
	}

	HRESULT Animation::Load(const std::wstring& Path)
	{
		return E_NOTIMPL;
	}

	void Animation::Update()
	{
		// 완료될 때 까지
		if (!bComplete)
		{
			// 타이머 재생
			mTime += Time::DeltaTime();

			// 스프라이트 하나의 재생 시간이 다 가기 전이면 계속 실행
			if (mAnimationSheet[mIndex].Duration < mTime)
			{
				mTime = 0.0f;

				if (mIndex < mAnimationSheet.size() - 1)
				{
					mIndex++;
				}
				else
				{
					bComplete = true;
				}
			}
		}
	}

	void Animation::Render(HDC Hdc)
	{
		if (mTexture)
		{
			Object*          ownerObject    = mAnimator->GetOwner();
			const Transform* ownerTransform = ownerObject->GetComponent<Transform>();
			Vector2          ownerPosition  = ownerTransform->GetPosition();

			if (Renderer::mainCamera)
			{
				ownerPosition = Renderer::mainCamera->CalculatePosition(ownerPosition);
			}

			BLENDFUNCTION func;
			func.BlendOp             = AC_SRC_OVER;  // 블렌딩 함수 (SRC_OVER가 디폴트)
			func.BlendFlags          = 0;            // 무조건 0
			func.AlphaFormat         = AC_SRC_ALPHA; // 비트맵에 알파채널이 존재함
			func.SourceConstantAlpha = 255;          // 소스 이미지 투명도 (0 ~ 255)

			// 재생 될 애니메이션 스프라이트
			Sprite animationSprite = mAnimationSheet[mIndex];
			// 디바이스 컨텍스트
			HDC imageHDC = mTexture->GetHdc();

			AlphaBlend(Hdc,
			           ownerPosition.X, ownerPosition.Y,
			           animationSprite.Size.X * 5,
			           animationSprite.Size.Y * 5,
			           imageHDC,
			           animationSprite.LeftTop.X,
			           animationSprite.LeftTop.Y,
			           animationSprite.Size.X,
			           animationSprite.Size.Y,
			           func);
		}
	}

	void Animation::CreateAnimation(const std::wstring&  Name, Texture* SpriteSheet, const Math::Vector2& LeftTop,
	                                const Math::Vector2& Size, const Math::Vector2& Offset, const UINT SpriteLength,
	                                const float          Duration)
	{
		mTexture = SpriteSheet;

		for (size_t i = 0; i < SpriteLength; ++i)
		{
			Sprite newSprite;
			newSprite.LeftTop.X = LeftTop.X + (Size.X * i);
			newSprite.LeftTop.Y = LeftTop.Y;
			newSprite.Size      = Size;
			newSprite.Offset    = Offset;
			newSprite.Duration  = Duration;

			mAnimationSheet.push_back(newSprite);
		}
	}

	void Animation::CreateAnimation(const std::wstring& Name, Texture* Sprites[], const UINT SpriteSize,
	                                const float         Duration)
	{
		for (size_t i = 0; i < SpriteSize; ++i)
		{
			Sprite newSprite;
			newSprite.Duration = Duration;

			mAnimationSheet.push_back(newSprite);
		}
	}

	void Animation::Reset()
	{
		mTime     = 0.f;
		mIndex    = 0;
		bComplete = false;
	}
}
