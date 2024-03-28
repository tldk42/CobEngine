#include "CobPlayer.h"

#include "CobInput.h"
#include "CobTime.h"
#include "CobTransform.h"

void Cob::Player::Initialize()
{
	Object::Initialize();
}

void Cob::Player::Update()
{
	Object::Update();
}

void Cob::Player::LateUpdate()
{
	Object::LateUpdate();

	if (Input::GetKey(EKeyCode::Right))
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		pos.x += 100.f * Time::DeltaTime();
		tr->SetPosition(pos);
	}
}

void Cob::Player::Render(HDC Hdc)
{
	Object::Render(Hdc);
}
