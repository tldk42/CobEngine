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
		// �̹��� Ȯ���� ����
		const std::wstring extenstion = Path.substr(Path.find_last_of(L".") + 1);

		// bmp Ÿ�� �̹���
		if (extenstion == L"bmp")
		{
			// ��Ʈ�� ���� �̹����� �ҷ��´�
			mTextureType = ETextureType::Bmp;
			mBitmap = static_cast<HBITMAP>(
				LoadImageW(nullptr, Path.c_str(), IMAGE_BITMAP, 0, 0,
				           LR_LOADFROMFILE | LR_CREATEDIBSECTION));

			// ��Ʈ���� ���������� �ҷ����� �� ��Ʈ�� ���� ���� 
			if (mBitmap)
			{
				// ��Ʈ�� ������ info�� ����
				BITMAP info;
				GetObject(mBitmap, sizeof(BITMAP), &info);

				// �ؽ�ó �ʺ� ���� ����
				mWidth = info.bmWidth;
				mHeight = info.bmHeight;

				// ����ǰ� �ִ� ���� �ڵ�� ȣȯ�Ǵ� ����̽����ؽ�Ʈ ����
				HDC mainDC = application.GetHdc();
				mHdc = CreateCompatibleDC(mainDC);

				// ������ ���Ǵ� ��Ʈ�� ����
				HBITMAP oldBitmap = static_cast<HBITMAP>(SelectObject(mHdc, mBitmap));
				DeleteObject(oldBitmap);

				return S_OK;
			}
		}
		// png Ÿ�� �̹���
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
