#pragma once
#include "CobComponent.h"

namespace Cob
{
	using namespace Math;

	class Camera : public Component
	{
	public:
		Camera();
		~Camera();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC Hdc) override;

		FORCEINLINE void SetTarget(Object* Target) { mViewTarget = Target; }
		FORCEINLINE void SetViewTarget(Object* Target) { mViewTarget = Target; }


		FORCEINLINE Vector2 CalculatePosition(const Vector2& Position) const
		{
			return Position - mDistance;
		}

	private:
		Object* mViewTarget;
		Vector2 mDistance;
		Vector2 mResolution;
		Vector2 mLookPosition;
	};
}
