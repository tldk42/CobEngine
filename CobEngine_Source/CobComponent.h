#pragma once
#include "CobEntity.h"

namespace Cob
{
	class Object;

	/**
	 * \brief ������Ʈ�� �߰��� �� �ִ� ��ü
	 */
	class Component : public Entity
	{
	public:
		Component();
		~Component();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC Hdc);

		[[noreturn]] void SetOwner(Object* Owner) { mOwner = Owner; }
		[[nodiscard]] Object* GetOwner() const { return mOwner; }

	private:
		/** ������Ʈ�� ���� ������Ʈ */
		Object* mOwner;
	};
}
