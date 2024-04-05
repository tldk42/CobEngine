#include "CobTexture.h"
#include "CobApplication.h"

extern Cob::Application application;

namespace Cob
{
	Texture::Texture():
		Resource(EResourceType::Texture)
	{
	}

	Texture::~Texture()
	{
	}

	HRESULT Texture::Load(const std::wstring& Path)
	{
		const std::wstring extenstion = Path.substr(Path.find_last_of(L".") + 1);

		if (extenstion == L"bmp")
		{
			mTextureType = ETextureType::Bmp;
			mBitmap = static_cast<HBITMAP>(LoadImageW(nullptr, Path.c_str(), IMAGE_BITMAP, 0, 0,
			                                          LR_LOADFROMFILE | LR_CREATEDIBSECTION));
			if (mBitmap)
			{
				BITMAP info;
				GetObject(mBitmap, sizeof(BITMAP), &info);

				mWidth = info.bmWidth;
				mHeight = info.bmHeight;

				HDC mainDC = application.GetHdc();
				mHdc = CreateCompatibleDC(mainDC);

				HBITMAP oldBitmap = static_cast<HBITMAP>(SelectObject(mHdc, mBitmap));
				DeleteObject(oldBitmap);

				return S_OK;
			}
		}
		else if (extenstion == L"png")
		{
			mTextureType = ETextureType::Png;
			mImage = Gdiplus::Image::FromFile(Path.c_str());

			if (mImage)
			{
				mWidth = mImage->GetWidth();
				mHeight = mImage->GetHeight();

				return S_OK;
			}
		}

		return S_FALSE;
	}
}
