#include "CobComponent.h"

namespace Cob
{
	Component::Component()
	{
	}

	Component::Component(EComponentType ComponentType)
		: mComponentType(ComponentType)
	{
	}

	Component::~Component()
	{
	}

	void Component::Initialize()
	{
	}

	void Component::Update()
	{
	}

	void Component::LateUpdate()
	{
	}

	void Component::Render(HDC Hdc)
	{
	}
}
