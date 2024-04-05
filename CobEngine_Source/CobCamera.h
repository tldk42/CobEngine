#pragma once
#include "CobComponent.h"

namespace Cob
{
	class Camera : public Component
	{
	public:
		Camera();
		~Camera();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC Hdc) override;

		FORCEINLINE Math::Vector2 CalculatePosition(const Math::Vector2& Position) const
		{
			return Position - mDistance;
		}

	private:
		Object* mViewTarget;
		Math::Vector2 mDistance;
		Math::Vector2 mResolution;
		Math::Vector2 mLookPosition;
	};
}
