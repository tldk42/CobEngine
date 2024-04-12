#pragma once
#include "CobObject.h"

namespace Cob
{
	/**
	 * \brief 프로그램 어플리케이션 (새 화면을 만들 때 이 클래스를 이용)
	 */
	class Application
	{
	public:
		Application();
		~Application();

		void Initialize(HWND Hwnd, UINT Width, UINT Height);
		void Run();

		void Update();
		void LateUpdate();
		void Render();
		void Release();

#pragma region Getter
		FORCEINLINE HWND GetHwnd() const { return mHwnd; }
		FORCEINLINE HDC  GetHdc() const { return mHdc; }
		FORCEINLINE UINT GetWidth() const { return mWidth; }
		FORCEINLINE UINT GetHeight() const { return mHeight; }
#pragma endregion

	private:
		/** 백버퍼로 화면을 Clear */
		void ClearRenderTarget();
		/** 백버퍼화면을 프론트버퍼로 복사 */
		void CopyRenderTarget(HDC Source, HDC Dest);
		/** 윈도우창 너비 설정 및 초기화 */
		void AdjustWindowRect_Implement(HWND Hwnd, UINT Width, UINT Height);
		/** 백버퍼 생성 */
		void CreateBuffer(UINT Width, UINT Height);
		/** 추가 컴포넌트 초기화 진행 */
		void InitializeEtc();

	private:
		/** 윈도우 핸들ㅣ */
		HWND mHwnd;

		/** Device Context */
		HDC mHdc;
		/** Back Device Context */
		HDC mBackHdc;
		/** BackBitmap */
		HBITMAP mBackBitmap;

		UINT mWidth;
		UINT mHeight;
	};
}
