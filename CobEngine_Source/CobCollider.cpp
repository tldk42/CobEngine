#include "CobCollider.h"

#include "CobObject.h"
#include "CobScript.h"

namespace Cob
{
	UINT Collider::CollisionID = 1;

	Collider::Collider()
		: Component(EComponentType::Collider),
		  mID(CollisionID++),
		  mSize(Math::Vector2::ONE),
		  mDebugColor(RGB(12, 87, 12))
	{
	}

	Collider::~Collider()
	{
	}

	void Collider::Initialize()
	{
		Component::Initialize();
	}

	void Collider::Update()
	{
		Component::Update();
	}

	void Collider::LateUpdate()
	{
		Component::LateUpdate();
	}

	void Collider::Render(HDC Hdc)
	{
		Component::Render(Hdc);
	}

	void Collider::OnCollisionEnter(Collider* Other)
	{
		if (Script* script = GetOwner()->GetComponent<Script>())
		{
			script->OnCollisionEnter(Other);
		}
	}

	void Collider::OnCollisionStay(Collider* Other)
	{
		Script* script = GetOwner()->GetComponent<Script>();
		script->OnCollisionStay(Other);
	}

	void Collider::OnCollisionExit(Collider* Other)
	{
		Script* script = GetOwner()->GetComponent<Script>();
		script->OnCollisionExit(Other);
	}

	void Collider::SetInitValue(const Math::Vector2& Offset, const Math::Vector2& Size)
	{
		mOffset = Offset;
		mSize   = Size;
	}
}
