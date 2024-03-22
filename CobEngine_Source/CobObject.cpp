#include "CobObject.h"
#include "CobInput.h"

Cob::Object::Object()
	: mX(0.f),
	  mY(0.f)
{
}

Cob::Object::~Object()
{
}

void Cob::Object::Update()
{
	if (Input::GetKey(EKeyCode::A))
	{
		mX -= 0.01f;
	}

	if (Input::GetKey(EKeyCode::D))
	{
		mX += 0.01f;
	}

	if (Input::GetKey(EKeyCode::W))
	{
		mY -= 0.01f;
	}

	if (Input::GetKey(EKeyCode::S))
	{
		mY += 0.01f;
	}
}

void Cob::Object::LastUpdate()
{
}

void Cob::Object::Render(HDC hdc)
{
	HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));

	HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, blueBrush);

	HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	HPEN oldPen = (HPEN)SelectObject(hdc, redPen);
	SelectObject(hdc, oldPen);

	Rectangle(hdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);

	SelectObject(hdc, oldBrush);
	DeleteObject(blueBrush);
	DeleteObject(redPen);
}
