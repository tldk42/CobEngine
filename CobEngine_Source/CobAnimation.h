#pragma once
#include "CobResource.h"

namespace Cob
{
	class Texture;

	/**
	 * \brief 2D ��������Ʈ ����
	 */
	struct Sprite
	{
		/** �̹������� ���� ����� ��ġ �̹����� ����� */
		Math::Vector2 LeftTop;
		/** ��������Ʈ�� ũ�� */
		Math::Vector2 Size;
		/** �� �»�����κ����� �Ÿ� */
		Math::Vector2 Offset;
		/* ��������Ʈ �ִϸ��̼� ���� �ð� */
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

		/** Ÿ�̸�, ��������Ʈ �ؽ�ó �ʱ�ȭ */
		void Reset();

		/** �ִϸ��̼��� ���� ����Ǿ����� ���� */
		FORCEINLINE bool IsComplete() const { return bComplete; }
		/** ���ο� �ִϸ����͸� �Ҵ� */
		FORCEINLINE void SetAnimator(class Animator* InAnimator) { mAnimator = InAnimator; }

	private:
		/** �� �ִϸ��̼��� ������ �ִϸ����� ��ü */
		Animator* mAnimator;
		/** �ִϸ��̼��� ������ ��������Ʈ �迭 */
		std::vector<Sprite> mAnimationSheet;
		/** ���� ��������Ʈ �ؽ�ó */
		Texture* mTexture;

		/** ���� ��������Ʈ �ε��� */
		int mIndex;
		/** ���� ��� �ð� */
		float mTime;
		/** �ִϸ��̼� 1���� ������� */
		bool bComplete;
	};
}
