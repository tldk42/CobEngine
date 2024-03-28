#include "CobSpriteRenderer.h"

#include "CobObject.h"
#include "CobTransform.h"

namespace Cob
{
	SpriteRenderer::SpriteRenderer()
	{
	}

	SpriteRenderer::~SpriteRenderer()
	{
	}

	void SpriteRenderer::Initialize()
	{
		Component::Initialize();
	}

	void SpriteRenderer::Update()
	{
		Component::Update();
	}

	void SpriteRenderer::LateUpdate()
	{
		Component::LateUpdate();
	}

	void SpriteRenderer::Render(HDC Hdc)
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		if (tr)
		{
			Vector2 pos = tr->GetPosition();

			Gdiplus::Graphics graphics(Hdc);
			graphics.DrawImage(mImage, Gdiplus::Rect(pos.x, pos.y, mWidth, mHeight));
		}
	}

	void SpriteRenderer::LoadImage_Implement(const std::wstring& Path)
	{
		mImage = Gdiplus::Image::FromFile(Path.c_str());
		mWidth = mImage->GetWidth();
		mHeight = mImage->GetHeight();
	}
}
