#pragma once
#include "CommonInclude.h"

namespace Cob
{
	class Object
	{
	public:
		Object();
		~Object();

		void Update();
		void LastUpdate();
		void Render(HDC hdc);

#pragma region Getter
		FORCEINLINE float GetPositionX() const
		{
			return mX;
		}

		FORCEINLINE float GetPositionY() const
		{
			return mY;
		}
#pragma endregion

#pragma region Setter
		FORCEINLINE void SetPosition(const float x, const float y)
		{
			mX = x;
			mY = y;
		}

	private:
		float mX;
		float mY;
#pragma endregion
	};
}
