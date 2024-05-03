#include "BoxCollider2D.h"

#include "CobObject.h"

namespace Cob
{
	BoxCollider2D::BoxCollider2D()
	{
	}

	BoxCollider2D::~BoxCollider2D()
	{
	}

	void BoxCollider2D::Initialize()
	{
		Collider::Initialize();
	}

	void BoxCollider2D::Update()
	{
		Collider::Update();
	}

	void BoxCollider2D::LateUpdate()
	{
		Collider::LateUpdate();
	}

	void BoxCollider2D::Render(HDC Hdc)
	{
		const Transform* transform = mOwner->GetTransform();
		const Vector2    position  = transform->GetPosition();

		HBRUSH transparentBrush = static_cast<HBRUSH>(GetStockObject(NULL_BRUSH));
		HBRUSH oldBrush         = static_cast<HBRUSH>(SelectObject(Hdc, transparentBrush));

		HPEN greenPen = CreatePen(PS_SOLID, 3, mDebugColor);
		HPEN oldPen   = static_cast<HPEN>(SelectObject(Hdc, greenPen));

		Rectangle(
			Hdc,
			position.X + mOffset.X,
			position.Y + mOffset.Y,
			position.X + mOffset.X + mSize.X,
			position.Y + mOffset.Y + mSize.Y);

		SelectObject(Hdc, oldBrush);
		SelectObject(Hdc, oldPen);

		DeleteObject(greenPen);
	}
}
