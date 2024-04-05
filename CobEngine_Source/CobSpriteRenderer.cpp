#include "CobSpriteRenderer.h"

#include "CobObject.h"
#include "CobRenderer.h"
#include "CobTransform.h"

namespace Cob
{
	SpriteRenderer::SpriteRenderer()
		: Component(EComponentType::SpriteRenderer),
		  mTexture(nullptr),
		  mSize(Vector2::ONE)
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
		if (mTexture)
		{
			const Transform* transform = GetOwner()->GetComponent<Transform>();
			Vector2 position = transform->GetPosition();

			position = Renderer::mainCamera->CalculatePosition(position);

			switch (mTexture->GetTextureType())
			{
			case ETextureType::None:
			case ETextureType::Jpg:
				break;
			case ETextureType::Bmp:
				TransparentBlt(Hdc,
				               position.X, position.Y,
				               mTexture->GetWidth() * mSize.X, mTexture->GetHeight() * mSize.Y,
				               mTexture->GetHdc(), 0, 0, mTexture->GetWidth(), mTexture->GetHeight(),
				               RGB(255, 0, 255));
				break;
			case ETextureType::Png:
				Gdiplus::Graphics graphics(Hdc);
				graphics.DrawImage(mTexture->GetImage(),
				                   Gdiplus::Rect(position.X, position.Y, mTexture->GetWidth() * mSize.X,
				                                 mTexture->GetHeight() * mSize.Y));
				break;
			}
		}
	}
}
