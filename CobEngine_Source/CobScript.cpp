#include "CobScript.h"

namespace Cob
{
	Script::Script()
		: Component(EComponentType::Script)
	{
	}

	Script::~Script()
	{
	}

	void Script::Initialize()
	{
		Component::Initialize();
	}

	void Script::Update()
	{
		Component::Update();
	}

	void Script::LateUpdate()
	{
		Component::LateUpdate();
	}

	void Script::Render(HDC Hdc)
	{
		Component::Render(Hdc);
	}
}
