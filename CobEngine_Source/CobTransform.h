#pragma once
#include "CobComponent.h"

namespace Cob
{
	using namespace Math;

	/** 위치 변환 컴포넌트 (2D) */
	class Transform : public Component
	{
	public:
		Transform();
		~Transform();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC Hdc) override;

#pragma region Setter
		FORCEINLINE void SetPosition(const Vector2& NewPosition)
		{
			mPosition = NewPosition;
		}

		FORCEINLINE void SetScale(const Vector2& NewScale)
		{
			mScale = NewScale;
		}

		FORCEINLINE void SetRotation(const float NewRotation)
		{
			mRotation = NewRotation;
		}
#pragma endregion

#pragma region Getter
		FORCEINLINE Vector2 GetPosition() const { return mPosition; }
		FORCEINLINE Vector2 GetScale() const { return mScale; }
		FORCEINLINE float GetRotation() const { return mRotation; }
#pragma endregion

	private:
		Vector2 mPosition;
		Vector2 mScale;
		float mRotation;
	};
}
