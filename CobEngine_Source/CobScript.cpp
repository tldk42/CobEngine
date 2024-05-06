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

	void Script::OnCollisionEnter(Collider* Other)
	{
	}

	void Script::OnCollisionStay(Collider* Other)
	{
	}

	void Script::OnCollisionExit(Collider* Other)
	{
	}
}
