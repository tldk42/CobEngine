#include "CobScene.h"

#include "CobLayer.h"
#include "CobObject.h"

namespace Cob
{
	Scene::Scene()
		: mLayers{}
	{
		CreateLayers();
	}

	Scene::~Scene()
	{
		for (Layer* layer : mLayers)
		{
			delete layer;
			layer = nullptr;
		}
	}

	void Scene::Initialize()
	{
		for (Layer* layer : mLayers)
		{
			if (layer == nullptr)
				continue;

			layer->Initialize();
		}
	}

	void Scene::Update()
	{
		for (Layer* layer : mLayers)
		{
			if (layer == nullptr)
				continue;

			layer->Update();
		}
	}

	void Scene::LateUpdate()
	{
		for (Layer* layer : mLayers)
		{
			if (layer == nullptr)
				continue;

			layer->LateUpdate();
		}
	}

	void Scene::Render(HDC Hdc)
	{
		for (Layer* layer : mLayers)
		{
			layer->Render(Hdc);
		}
	}

	void Scene::Destroy()
	{
		for (Layer* layer : mLayers)
		{
			if (layer)
			{
				layer->Destroy();
			}
		}
	}

	void Scene::OnEnter()
	{
	}

	void Scene::OnExit()
	{
	}

	void Scene::AddGameObject(Object* GameObject, const ELayerType Layer)
	{
		mLayers[(UINT)Layer]->AddObject(GameObject);
	}

	void Scene::DeleteObject(Object* Object)
	{
		mLayers[static_cast<UINT>(Object->GetLayerType())]->DeleteObject(Object);
	}

	void Scene::CreateLayers()
	{
		mLayers.resize((UINT)ELayerType::Max);

		for (size_t i = 0; i < (UINT)ELayerType::Max; ++i)
		{
			mLayers[i] = new Layer;
		}
	}
}
