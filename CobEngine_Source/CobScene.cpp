#include "CobScene.h"
#include "CobObject.h"

namespace Cob
{
	Scene::Scene()
		: mGameObjects{}
	{
	}

	Scene::~Scene()
	{
	}

	void Scene::Initialize()
	{
	}

	void Scene::Update()
	{
		for (Object* gameObject : mGameObjects)
		{
			gameObject->Update();
		}
	}

	void Scene::LateUpdate()
	{
		for (Object* gameObject : mGameObjects)
		{
			gameObject->LateUpdate();
		}
	}

	void Scene::Render(HDC Hdc)
	{
		for (Object* gameObject : mGameObjects)
		{
			gameObject->Render(Hdc);
		}
	}

	void Scene::AddGameObject(Object* GameObject)
	{
		mGameObjects.push_back(GameObject);
	}
}


