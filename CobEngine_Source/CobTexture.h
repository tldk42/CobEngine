#pragma once
#include "CobResource.h"

namespace Cob
{
	/**
	 * \brief 텍스처 베이스클래스
	 */
	class Texture : public Resource
	{
	public:
		Texture();
		~Texture();

		/**
		 * \brief 이미지를 경로로부터 가져와 이미지 정보를 저장
		 * \param Path 이미지 파일 경로
		 * \return 로드 성공여부
		 */
		HRESULT Load(const std::wstring& Path) override;

#pragma region Getter
		FORCEINLINE UINT GetWidth() const { return mWidth; }
		FORCEINLINE UINT GetHeight() const { return mHeight; }
		FORCEINLINE HDC GetHdc() const { return mHdc; }
		FORCEINLINE ETextureType GetTextureType() const { return mTextureType; }
		FORCEINLINE Gdiplus::Image* GetImage() const { return mImage; }
#pragma endregion

	private:
		ETextureType mTextureType;
		Gdiplus::Image* mImage;
		HBITMAP mBitmap;
		HDC mHdc;

		UINT mWidth;
		UINT mHeight;
	};
}
