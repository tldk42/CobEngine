#pragma once
<<<<<<< HEAD
#include "CommonInclude.h"

namespace Cob
{
=======
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

>>>>>>> 05220025e134bab7820fcdee72603266979b8482
	class CollisionManager
	{
	public:
		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC Hdc);

<<<<<<< HEAD
		static void CollisionLayerCheck(const ELayerType Left, const ELayerType Right, const bool bEnable);

	private:
		static std::bitset<static_cast<UINT>(ELayerType::Max)> mCollisionLayerMatrix[static_cast<UINT>(ELayerType::Max)];
=======
		static void CollisionLayerCheck(ELayerType Left, ELayerType Right, bool bEnable);
		static void LayerCollision(class Scene* Scene, ELayerType Left, ELayerType Right);
		static void ColliderCollision(Collider* Left, Collider* Right);
		static bool Intersaect(Collider* Left, Collider* Right);

	private:
		static std::bitset<static_cast<UINT>(ELayerType::Max)> mCollisionLayerMatrix[(static_cast<UINT>(
			ELayerType::Max))];

		static std::unordered_map<UINT64, bool> mCollisionMap;
>>>>>>> 05220025e134bab7820fcdee72603266979b8482
	};
}
