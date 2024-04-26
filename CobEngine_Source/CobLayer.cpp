#include "CobLayer.h"
#include "CobObject.h"

namespace Cob
{
	Layer::Layer()
		: mObjects{}
	{
	}

	Layer::~Layer()
	{
		for (Object* obj : mObjects)
		{
			if (obj)
			{
				delete obj;
				obj = nullptr;
			}
		}
	}

	void Layer::Initialize()
	{
		for (Object* object : mObjects)
		{
			if (object)
			{
				object->Initialize();
			}
		}
	}

	void Layer::Update()
	{
		for (Object* gameObj : mObjects)
		{
			if (gameObj == nullptr)
				continue;

			gameObj->Update();
		}
	}

	void Layer::LateUpdate()
	{
		for (Object* gameObj : mObjects)
		{
			if (gameObj == nullptr)
				continue;

			gameObj->LateUpdate();
		}
	}

	void Layer::Render(HDC Hdc)
	{
		for (Object* gameObj : mObjects)
		{
			if (gameObj == nullptr)
				continue;

			gameObj->Render(Hdc);
		}
	}

	void Layer::Destroy()
	{
		for (ObjectIter iter = mObjects.begin(); iter != mObjects.end();)
		{
			EObjectState State = (*iter)->GetState();
			if (State == EObjectState::Dead)
			{
				Object* DeadObj = *iter;
				iter            = mObjects.erase(iter);

				delete DeadObj;
				DeadObj = nullptr;
			}

			++iter;
		}
	}

	void Layer::AddObject(Object* Object)
	{
		if (Object)
		{
			mObjects.push_back(Object);
		}
	}
}
