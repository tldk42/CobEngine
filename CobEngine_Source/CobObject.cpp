#include "CobObject.h"
#include "CobInput.h"

namespace Cob
{
	Object::Object()
	{
		InitializeTransform();
	}

	Object::~Object()
	{
		for (const Component* comp : mComponents)
		{
			delete comp;
			comp = nullptr;
		}
	}

	void Object::Initialize()
	{
		for (Component* comp : mComponents)
		{
			comp->Initialize();
		}
	}

	void Object::Update()
	{
		for (Component* comp : mComponents)
		{
			comp->Update();
		}
	}

	void Object::LateUpdate()
	{
		for (Component* comp : mComponents)
		{
			comp->LateUpdate();
		}
	}

	void Object::Render(HDC Hdc)
	{
		for (Component* comp : mComponents)
		{
			comp->Render(Hdc);
		}
	}

	void Object::InitializeTransform()
	{
		AddComponent<Transform>();
	}
}
