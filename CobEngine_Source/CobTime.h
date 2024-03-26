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
		/** ����� CPU ���� Ŭ�� */
		static LARGE_INTEGER CpuFrequency;
		/** ������ ������ Ŭ�� �ӵ� */
		static LARGE_INTEGER PrevFrequency;
		/** ���� ������ Ŭ�� �ӵ�*/
		static LARGE_INTEGER CurrentFrequency;
		/** 1�����ӱ����� �ɸ� �ð� */
		static float DeltaTimeValue;
	};
}
