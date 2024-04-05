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
		Component(EComponentType ComponentType);
		~Component();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC Hdc);

		FORCEINLINE void SetOwner(Object* Owner) { mOwner = Owner; }
		FORCEINLINE Object* GetOwner() const { return mOwner; }
		FORCEINLINE EComponentType GetType() const { return mComponentType; }

	private:
		/** ������Ʈ�� ���� ������Ʈ */
		Object* mOwner;

		EComponentType mComponentType;
	};
}
