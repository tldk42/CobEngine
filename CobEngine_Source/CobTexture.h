#pragma once
#include "CobResource.h"

namespace Cob
{
	/**
	 * \brief �ؽ�ó ���̽�Ŭ����
	 */
	class Texture : public Resource
	{
	public:
		Texture();
		~Texture();

	public:
		static Texture* Create(const std::wstring& Name, UINT InWidth, UINT InHeight);

		/**
		 * \brief �̹����� ��ηκ��� ������ �̹��� ������ ����
		 * \param Path �̹��� ���� ���
		 * \return �ε� ��������
		 */
		virtual HRESULT Load(const std::wstring& Path) override;

#pragma region Getter
		FORCEINLINE UINT            GetWidth() const { return mWidth; }
		FORCEINLINE UINT            GetHeight() const { return mHeight; }
		FORCEINLINE HDC             GetHdc() const { return mHdc; }
		FORCEINLINE ETextureType    GetTextureType() const { return mTextureType; }
		FORCEINLINE Gdiplus::Image* GetImage() const { return mImage; }
#pragma endregion

#pragma region Setter
		FORCEINLINE void SetWidth(const UINT InWidth) { mWidth = InWidth; }
		FORCEINLINE void SetHeight(const UINT InHeight) { mHeight = InHeight; }
#pragma endregion

	private:
		ETextureType    mTextureType;
		Gdiplus::Image* mImage;
		HBITMAP         mBitmap;
		HDC             mHdc;

		UINT mWidth;
		UINT mHeight;
		bool bAlpha;
	};
}
