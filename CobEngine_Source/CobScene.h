#pragma once
#include "CobEntity.h"

namespace Cob
{
	class Layer;
	class Object;

	/**
	 * \brief 화면에 보여질 오브젝트들을 관리
	 */
	class Scene : public Entity
	{
	public:
		Scene();
		~Scene();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC Hdc);
		virtual void Destroy();


		virtual void OnEnter();
		virtual void OnExit();

		void   AddGameObject(Object* GameObject, const ELayerType Layer);
		void   DeleteObject(Object* Object);
		Layer* GetLayer(const ELayerType Type) { return mLayers[static_cast<UINT>(Type)]; }

	private:
		void CreateLayers();

	private:
		std::vector<Layer*> mLayers;
	};
}
