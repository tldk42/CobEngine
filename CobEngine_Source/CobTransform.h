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
#pragma endregion

#pragma region Getter
		FORCEINLINE Vector2 GetPosition() const { return mPosition; }
#pragma endregion

	private:
		Vector2 mPosition;
	};
}
