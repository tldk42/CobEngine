#include "CobTime.h"


namespace Cob
{
	LARGE_INTEGER Time::CpuFrequency = {};
	LARGE_INTEGER Time::PrevFrequency = {};
	LARGE_INTEGER Time::CurrentFrequency = {};
	float Time::DeltaTimeValue = 0.f;

	/** 고유 클럭과 최초 클럭을 로드 */
	void Time::Initialize()
	{
		QueryPerformanceFrequency(&CpuFrequency);

		QueryPerformanceCounter(&PrevFrequency);
	}

	/** 현재 클럭 - 이전 클럭으로 DeltaTime을 업데이트 */
	void Time::Update()
	{
		QueryPerformanceCounter(&CurrentFrequency);

		const float differentFrequency = static_cast<float>(CurrentFrequency.QuadPart - PrevFrequency.QuadPart);

		DeltaTimeValue = differentFrequency / static_cast<float>(CpuFrequency.QuadPart);

		PrevFrequency.QuadPart = CurrentFrequency.QuadPart;
	}

	/** 화면 좌상단(0, 0)에 현재 fps를 표시 */
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
