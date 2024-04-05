#pragma once
#include "CobEntity.h"

namespace Cob
{
	class Object;

	/**
	 * \brief 오브젝트에 추가할 수 있는 개체
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
		/** 컴포넌트의 소유 오브젝트 */
		Object* mOwner;

		EComponentType mComponentType;
	};
}
