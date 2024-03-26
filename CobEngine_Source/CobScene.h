#pragma once
#include "CobEntity.h"

namespace Cob
{
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

		void AddGameObject(Object* GameObject);

	private:
		std::vector<Object*> mGameObjects;
	};
}
