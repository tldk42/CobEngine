#pragma once
#include "CobEntity.h"

namespace Cob
{
	class Object;

	/**
	 * \brief ȭ�鿡 ������ ������Ʈ���� ����
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
