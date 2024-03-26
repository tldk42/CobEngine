#pragma once
#include "CommonInclude.h"

namespace Cob
{
	class Time
	{
	public:
		static void Initialize();
		static void Update();
		static void Render(HDC Hdc);

		FORCEINLINE static float DeltaTime() { return DeltaTimeValue; }

	private:
		/** 사용자 CPU 고유 클럭 */
		static LARGE_INTEGER CpuFrequency;
		/** 이전에 측정된 클럭 속도 */
		static LARGE_INTEGER PrevFrequency;
		/** 현재 측정된 클럭 속도*/
		static LARGE_INTEGER CurrentFrequency;
		/** 1프레임까지의 걸린 시간 */
		static float DeltaTimeValue;
	};
}
