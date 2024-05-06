#include "CobCollisionManager.h"

namespace Cob
{
	std::bitset<static_cast<UINT>(ELayerType::Max)> CollisionManager::mCollisionLayerMatrix[static_cast<UINT>(
		ELayerType::Max)] = {};

	void CollisionManager::Initialize() {}
	void CollisionManager::Update() {}
	void CollisionManager::LateUpdate() {}
	void CollisionManager::Render(HDC Hdc) {}

	void CollisionManager::CollisionLayerCheck(const ELayerType Left, const ELayerType Right, const bool bEnable)
	{
		int row, col;

		if (Left <= Right)
		{
			row = static_cast<UINT>(Left);
			col = static_cast<UINT>(Right);
		}
		else
		{
			row = static_cast<UINT>(Right);
			col = static_cast<UINT>(Left);
		}

		mCollisionLayerMatrix[row][col] = bEnable;
	}
}
