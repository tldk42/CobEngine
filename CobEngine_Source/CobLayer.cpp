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
		for (Object* object : mObjects)
		{
			if (object)
			{
				delete object;
				object = nullptr;
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

	void Layer::AddObject(Object* Object)
	{
		if (Object)
		{
			mObjects.push_back(Object);
		}
	}
}
