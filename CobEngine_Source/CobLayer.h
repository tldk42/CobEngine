#pragma once
#include "CobEntity.h"

namespace Cob
{
	class Object;
}

namespace Cob
{
	class Layer : public Entity
	{
	public:
		Layer();
		~Layer();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC Hdc);

		void AddObject(Object* Object);

	private:
		std::vector<Object*> mObjects;
	};
}
