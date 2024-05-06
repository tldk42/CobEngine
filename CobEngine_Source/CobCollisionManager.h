#pragma once
#include "CommonInclude.h"

namespace Cob
{
	class CollisionManager
	{
	public:
		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC Hdc);

		static void CollisionLayerCheck(const ELayerType Left, const ELayerType Right, const bool bEnable);

	private:
		static std::bitset<static_cast<UINT>(ELayerType::Max)> mCollisionLayerMatrix[static_cast<UINT>(ELayerType::Max)];
	};
}
