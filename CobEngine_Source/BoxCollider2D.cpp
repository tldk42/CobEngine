#include "BoxCollider2D.h"

#include "CobObject.h"
#include "CobTransform.h"

namespace Cob
{
	BoxCollider2D::BoxCollider2D()
		: Collider(),
		  mSize({20.f, 20.f}) {}

	BoxCollider2D::~BoxCollider2D() {}

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
		HBRUSH transparentBrush = static_cast<HBRUSH>(GetStockObject(NULL_BRUSH));
		HBRUSH oldBrush         = static_cast<HBRUSH>(SelectObject(Hdc, transparentBrush));

		HPEN pen = CreatePen(PS_SOLID, 2, RGB(12, 180, 12));
		HPEN oldPen = static_cast<HPEN>(SelectObject(Hdc, pen));

		const Transform* ownerTransform = mOwner->GetTransform();
		const Vector2    ownerPosition  = ownerTransform->GetPosition();

		Rectangle(Hdc,
		          ownerPosition.X + mOffset.X,
		          ownerPosition.Y + mOffset.Y,
		          ownerPosition.X + mOffset.X + mSize.X,
		          ownerPosition.Y + mOffset.Y + mSize.Y);

		SelectObject(Hdc, oldBrush);
		SelectObject(Hdc, oldPen);

		DeleteObject(pen);
	}
}
