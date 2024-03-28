#include "CobLayer.h"

#include "CobObject.h"

Cob::Layer::Layer()
	: mObjects{}
{
}

Cob::Layer::~Layer()
{
}

void Cob::Layer::Initialize()
{
	for (Object* object : mObjects)
	{
		if (object)
		{
			object->Initialize();
		}
	}
}

void Cob::Layer::Update()
{
	for (Object* gameObj : mObjects)
	{
		if (gameObj == nullptr)
			continue;

		gameObj->Update();
	}
}

void Cob::Layer::LateUpdate()
{
	for (Object* gameObj : mObjects)
	{
		if (gameObj == nullptr)
			continue;

		gameObj->LateUpdate();
	}
}

void Cob::Layer::Render(HDC Hdc)
{
	for (Object* gameObj : mObjects)
	{
		if (gameObj == nullptr)
			continue;

		gameObj->Render(Hdc);
	}
}

void Cob::Layer::AddObject(Object* Object)
{
	if (Object)
	{
		mObjects.push_back(Object);
	}
}
