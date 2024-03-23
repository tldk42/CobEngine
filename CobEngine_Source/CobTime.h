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
		static LARGE_INTEGER CpuFrequency;
		static LARGE_INTEGER PrevFrequency;
		static LARGE_INTEGER CurrentFrequency;
		static float DeltaTimeValue;
	};
}
