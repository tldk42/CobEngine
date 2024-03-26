#include "CobTransform.h"

Cob::Transform::Transform()
{
}

Cob::Transform::~Transform()
{
}

void Cob::Transform::Initialize()
{
	Component::Initialize();
}

void Cob::Transform::Update()
{
	Component::Update();
}

void Cob::Transform::LateUpdate()
{
	Component::LateUpdate();
}

void Cob::Transform::Render(HDC Hdc)
{
	Component::Render(Hdc);
}
