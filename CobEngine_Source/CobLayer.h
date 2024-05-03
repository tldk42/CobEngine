#pragma once
#include "CobEntity.h"

namespace Cob
{
	class Object;
}

namespace Cob
{
	using ObjectIter = std::vector<Object*>::iterator;

	class Layer : public Entity
	{
	public:
		Layer();
		~Layer();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC Hdc);
		virtual void Destroy();

		void AddObject(Object* Object);
		void DeleteObject(Object* ObjectToDelete);

		const std::vector<Object*> GetObjects() const { return mObjects; }

	private:
		void FindDeadObjects(OUT std::vector<Object*>& Objects) const;
		void DeleteObjects(std::vector<Object*> Objects);
		void DeleteDeadObject();

	private:
		std::vector<Object*> mObjects;
	};
}
