#include "CobObject.h"
#include "CobInput.h"
#include "CobTime.h"

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
	const int speed = 100.f;

	if (Input::GetKey(EKeyCode::A))
	{
		mX -= speed * Time::DeltaTime();
	}

	if (Input::GetKey(EKeyCode::D))
	{
		mX += speed * Time::DeltaTime();
	}

	if (Input::GetKey(EKeyCode::W))
	{
		mY -= speed * Time::DeltaTime();
	}

	if (Input::GetKey(EKeyCode::S))
	{
		mY += speed * Time::DeltaTime();
	}
}

void Cob::Object::LastUpdate()
{
}

void Cob::Object::Render(HDC Hdc)
{
	HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));

	HBRUSH oldBrush = (HBRUSH)SelectObject(Hdc, blueBrush);

	HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	HPEN oldPen = (HPEN)SelectObject(Hdc, redPen);
	SelectObject(Hdc, oldPen);

	Rectangle(Hdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);

	SelectObject(Hdc, oldBrush);
	DeleteObject(blueBrush);
	DeleteObject(redPen);
}
