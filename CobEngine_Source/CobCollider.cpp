#include "CobCollider.h"

namespace Cob
{
	Collider::Collider()
		: Component(EComponentType::Collider) {}

	Collider::~Collider() {}

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
}
