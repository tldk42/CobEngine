#pragma once
#include "CobComponent.h"

namespace Cob
{
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
		FORCEINLINE void SetPosition(const float X, const float Y)
		{
			mX = X;
			mY = Y;
		}
#pragma endregion

#pragma region Getter
		FORCEINLINE float GetX() const { return mX; }
		FORCEINLINE float GetY() const { return mY; }
#pragma endregion

	private:
		float mX;
		float mY;
	};
}
