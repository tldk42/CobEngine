#include "CobTime.h"


namespace Cob
{
	LARGE_INTEGER Time::CpuFrequency = {};
	LARGE_INTEGER Time::PrevFrequency = {};
	LARGE_INTEGER Time::CurrentFrequency = {};
	float Time::DeltaTimeValue = 0.f;

	void Time::Initialize()
	{
		QueryPerformanceFrequency(&CpuFrequency);

		QueryPerformanceCounter(&PrevFrequency);
	}

	void Time::Update()
	{
		QueryPerformanceCounter(&CurrentFrequency);

		const float differentFrequency = static_cast<float>(CurrentFrequency.QuadPart - PrevFrequency.QuadPart);

		DeltaTimeValue = differentFrequency / static_cast<float>(CpuFrequency.QuadPart);

		PrevFrequency.QuadPart = CurrentFrequency.QuadPart;
	}

	void Time::Render(HDC Hdc)
	{
		static float time = 0.f;


		time += DeltaTimeValue;
		const float fps = 1.f / DeltaTimeValue;

		wchar_t str[50] = L"";
		swprintf_s(str, 50, L"Time: %d", (int)fps);
		const int len = wcsnlen_s(str, 50);

		TextOut(Hdc, 0, 0, str, len);
	}
}
