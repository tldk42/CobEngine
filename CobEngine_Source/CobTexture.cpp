#include "CobTexture.h"
#include "CobApplication.h"
#include "CobResources.h"

extern Cob::Application application;

namespace Cob
{
	Texture::Texture():
		Resource(EResourceType::Texture),
		bAlpha(false)
	{
	}

	Texture::~Texture()
	{
	}

	Texture* Texture::Create(const std::wstring& Name, UINT InWidth, UINT InHeight)
	{
		Texture* imageTexture = Resources::Find<Texture>(Name);
		if (imageTexture)
		{
			return imageTexture;
		}

		imageTexture = new Texture;
		imageTexture->SetName(Name);
		imageTexture->SetWidth(InWidth);
		imageTexture->SetHeight(InHeight);

		HDC  hdc  = application.GetHdc();
		HWND hwnd = application.GetHwnd();

		imageTexture->mBitmap = CreateCompatibleBitmap(hdc, InWidth, InHeight);
		imageTexture->mHdc    = CreateCompatibleDC(hdc);

		HBRUSH transparentBrush = static_cast<HBRUSH>(GetStockObject(NULL_BRUSH));
		HBRUSH oldBrush         = static_cast<HBRUSH>(SelectObject(hdc, transparentBrush));
		Rectangle(imageTexture->mHdc, -1, -1, imageTexture->GetWidth() + 1, imageTexture->GetHeight() + 1);
		SelectObject(hdc, oldBrush);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(imageTexture->mHdc, imageTexture->mBitmap);
		DeleteObject(oldBitmap);

		Resources::Insert(Name + L"Image", imageTexture);

		return imageTexture;
	}

	HRESULT Texture::Load(const std::wstring& Path)
	{
		// 이미지 확장자 구분
		const std::wstring extenstion = Path.substr(Path.find_last_of(L".") + 1);

		// bmp 타입 이미지
		if (extenstion == L"bmp")
		{
			// 비트맵 파일 이미지를 불러온다
			mTextureType = ETextureType::Bmp;
			mBitmap      = static_cast<HBITMAP>(
				LoadImageW(nullptr, Path.c_str(), IMAGE_BITMAP, 0, 0,
				           LR_LOADFROMFILE | LR_CREATEDIBSECTION));

			// 비트맵을 성공적으로 불러왔을 때 비트맵 정보 저장 
			if (mBitmap)
			{
				// 비트맵 정보를 info에 저장
				BITMAP info;
				GetObject(mBitmap, sizeof(BITMAP), &info);

				// 텍스처 너비 높이 저장
				mWidth  = info.bmWidth;
				mHeight = info.bmHeight;

				// 실행되고 있는 메인 핸들과 호환되는 디바이스컨텍스트 생성
				HDC mainDC = application.GetHdc();
				mHdc       = CreateCompatibleDC(mainDC);

				// 이전에 사용되던 비트맵 제거
				HBITMAP oldBitmap = static_cast<HBITMAP>(SelectObject(mHdc, mBitmap));
				DeleteObject(oldBitmap);

				return S_OK;
			}
		}
		// png 타입 이미지
		else if (extenstion == L"png")
		{
			mTextureType = ETextureType::Png;
			mImage       = Gdiplus::Image::FromFile(Path.c_str());

			if (mImage)
			{
				mWidth  = mImage->GetWidth();
				mHeight = mImage->GetHeight();

				return S_OK;
			}
		}

		return S_FALSE;
	}
}
