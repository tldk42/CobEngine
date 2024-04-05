#include "CobObject.h"
#include "CobInput.h"

namespace Cob
{
	Object::Object()
	{
		mComponents.resize(static_cast<UINT>(EComponentType::End));
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
			if (comp)
			{
				comp->Initialize();
			}
		}
	}

	void Object::Update()
	{
		for (Component* comp : mComponents)
		{
			if (comp)
			{
				comp->Update();
			}
		}
	}

	void Object::LateUpdate()
	{
		for (Component* comp : mComponents)
		{
			if (comp)
			{
				comp->LateUpdate();
			}
		}
	}

	void Object::Render(HDC Hdc)
	{
		for (Component* comp : mComponents)
		{
			if (comp)
			{
				comp->Render(Hdc);
			}
		}
	}

	void Object::InitializeTransform()
	{
		AddComponent<Transform>();
	}
}
