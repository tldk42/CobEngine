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
			if (gameObj && (gameObj->GetState() != EObjectState::Dead || gameObj->GetState() != EObjectState::Paused))
			{
				gameObj->Update();
			}
		}
	}

	void Layer::LateUpdate()
	{
		for (Object* gameObj : mObjects)
		{
			if (gameObj && (gameObj->GetState() != EObjectState::Dead || gameObj->GetState() != EObjectState::Paused))
			{
				gameObj->LateUpdate();
			}
		}
	}

	void Layer::Render(HDC Hdc)
	{
		for (Object* gameObj : mObjects)
		{
			if (gameObj && (gameObj->GetState() != EObjectState::Dead || gameObj->GetState() != EObjectState::Paused))
			{
				gameObj->Render(Hdc);
			}
		}
	}

	void Layer::Destroy()
	{
		std::vector<Object*> deleteObjects = {};

		FindDeadObjects(deleteObjects);
		DeleteDeadObject();
		DeleteObjects(deleteObjects);
	}

	void Layer::AddObject(Object* Object)
	{
		if (Object)
		{
			mObjects.push_back(Object);
		}
	}

	void Layer::DeleteObject(Object* ObjectToDelete)
	{
		std::erase_if(mObjects, [=](Object* obj)
		{
			return ObjectToDelete == obj;
		});
	}

	void Layer::FindDeadObjects(std::vector<Object*>& Objects) const
	{
		for (Object* object : mObjects)
		{
			if (object->IsDead())
			{
				Objects.push_back(object);
			}
		}
	}

	void Layer::DeleteObjects(std::vector<Object*> Objects)
	{
		for (Object* object : Objects)
		{
			delete object;
			object = nullptr;
		}
	}

	void Layer::DeleteDeadObject()
	{
		std::erase_if(mObjects, [](Object* obj)
		{
			return obj->IsDead();
		});
	}
}
