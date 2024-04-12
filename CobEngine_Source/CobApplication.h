#pragma once
#include "CobObject.h"

namespace Cob
{
	/**
	 * \brief ���α׷� ���ø����̼� (�� ȭ���� ���� �� �� Ŭ������ �̿�)
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
		/** ����۷� ȭ���� Clear */
		void ClearRenderTarget();
		/** �����ȭ���� ����Ʈ���۷� ���� */
		void CopyRenderTarget(HDC Source, HDC Dest);
		/** ������â �ʺ� ���� �� �ʱ�ȭ */
		void AdjustWindowRect_Implement(HWND Hwnd, UINT Width, UINT Height);
		/** ����� ���� */
		void CreateBuffer(UINT Width, UINT Height);
		/** �߰� ������Ʈ �ʱ�ȭ ���� */
		void InitializeEtc();

	private:
		/** ������ �ڵ�� */
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
