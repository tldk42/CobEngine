#pragma once
#include <CommonInclude.h>

namespace Cob
{
	class Collider;
}

namespace Cob
{
	union CollisionID
	{
		struct
		{
			UINT left;
			UINT right;
		};

		UINT64 id;
	};

	class CollisionManager
	{
	public:
		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC Hdc);

		static void CollisionLayerCheck(ELayerType Left, ELayerType Right, bool bEnable);
		static void LayerCollision(class Scene* Scene, ELayerType Left, ELayerType Right);
		static void ColliderCollision(Collider* Left, Collider* Right);
		static bool Intersaect(Collider* Left, Collider* Right);

	private:
		static std::bitset<static_cast<UINT>(ELayerType::Max)> mCollisionLayerMatrix[(static_cast<UINT>(
			ELayerType::Max))];

		static std::unordered_map<UINT64, bool> mCollisionMap;
	};
}
