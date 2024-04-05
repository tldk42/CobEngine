#include "CobTransform.h"

namespace Cob
{
	Transform::Transform()
		: Component(EComponentType::Transform)
	{
	}

	Transform::~Transform()
	{
	}

	void Transform::Initialize()
	{
		Component::Initialize();
	}

	void Transform::Update()
	{
		Component::Update();
	}

	void Transform::LateUpdate()
	{
		Component::LateUpdate();
	}

	void Transform::Render(HDC Hdc)
	{
		Component::Render(Hdc);
	}
}
