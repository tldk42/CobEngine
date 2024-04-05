#include "CobPlayerScript.h"

#include "CobInput.h"
#include "CobObject.h"
#include "CobTime.h"
#include "CobTransform.h"

namespace Cob
{
	PlayerScript::PlayerScript()
	{
	}

	PlayerScript::~PlayerScript()
	{
	}

	void PlayerScript::Initialize()
	{
		Script::Initialize();
	}

	void PlayerScript::Update()
	{
		if (Input::GetKey(EKeyCode::Right))
		{
			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector2 pos = tr->GetPosition();
			pos.X += 100.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}
		if (Input::GetKey(EKeyCode::Left))
		{
			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector2 pos = tr->GetPosition();
			pos.X -= 100.0f * Time::DeltaTime();

			tr->SetPosition(pos);
		}
		if (Input::GetKey(EKeyCode::Up))
		{
			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector2 pos = tr->GetPosition();
			pos.Y -= 100.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}
		if (Input::GetKey(EKeyCode::Down))
		{
			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector2 pos = tr->GetPosition();
			pos.Y += 100.0f * Time::DeltaTime();

			tr->SetPosition(pos);
		}
	}

	void PlayerScript::LateUpdate()
	{
	}

	void PlayerScript::Render(HDC Hdc)
	{
	}
}
