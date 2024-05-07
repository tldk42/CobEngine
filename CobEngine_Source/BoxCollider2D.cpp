#include "BoxCollider2D.h"

#include "CobObject.h"
<<<<<<< HEAD
#include "CobTransform.h"
=======
>>>>>>> 05220025e134bab7820fcdee72603266979b8482

namespace Cob
{
	BoxCollider2D::BoxCollider2D()
<<<<<<< HEAD
		: Collider(),
		  mSize({20.f, 20.f}) {}

	BoxCollider2D::~BoxCollider2D() {}
=======
	{
	}

	BoxCollider2D::~BoxCollider2D()
	{
	}
>>>>>>> 05220025e134bab7820fcdee72603266979b8482

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
<<<<<<< HEAD
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
=======
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
>>>>>>> 05220025e134bab7820fcdee72603266979b8482

		SelectObject(Hdc, oldBrush);
		SelectObject(Hdc, oldPen);

<<<<<<< HEAD
		DeleteObject(pen);
=======
		DeleteObject(greenPen);
>>>>>>> 05220025e134bab7820fcdee72603266979b8482
	}
}
