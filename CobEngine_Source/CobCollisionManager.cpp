#include "CobCollisionManager.h"

<<<<<<< HEAD
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
=======
#include "CobCollider.h"
#include "CobLayer.h"
#include "CobObject.h"
#include "CobSceneManager.h"

namespace Cob
{
	std::bitset<static_cast<UINT>(ELayerType::Max)> CollisionManager::mCollisionLayerMatrix[static_cast<UINT>(
		ELayerType::Max)];
	std::unordered_map<UINT64, bool> CollisionManager::mCollisionMap;

	void CollisionManager::Initialize()
	{
	}

	void CollisionManager::Update()
	{
		Scene* scene = SceneManager::GetActiveScene();

		for (UINT row = 0; row < static_cast<UINT>(ELayerType::Max); ++row)
		{
			for (UINT col = 0; col < static_cast<UINT>(ELayerType::Max); ++col)
			{
				if (mCollisionLayerMatrix[row][col])
				{
					LayerCollision(scene, static_cast<ELayerType>(row), static_cast<ELayerType>(col));
				}
			}
		}
	}

	void CollisionManager::LateUpdate()
	{
	}

	void CollisionManager::Render(HDC Hdc)
	{
	}

	void CollisionManager::CollisionLayerCheck(ELayerType Left, ELayerType Right, bool bEnable)
	{
		int row = 0;
		int col = 0;
>>>>>>> 05220025e134bab7820fcdee72603266979b8482

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
<<<<<<< HEAD
=======

	void CollisionManager::LayerCollision(Scene* Scene, ELayerType Left, ELayerType Right)
	{
		const std::vector<Object*>& leftLayers  = Scene->GetLayer(Left)->GetObjects();
		const std::vector<Object*>& rightLayers = Scene->GetLayer(Right)->GetObjects();

		for (Object* leftLayer : leftLayers)
		{
			if (leftLayer->GetState() != EObjectState::Dead)
			{
				if (Collider* leftCollider = leftLayer->GetComponent<Collider>())
				{
					for (Object* rightLayer : rightLayers)
					{
						if (rightLayer->GetState() != EObjectState::Dead)
						{
							if (Collider* rightCollider = rightLayer->GetComponent<Collider>())
							{
								if (rightCollider != leftCollider)
								{
									ColliderCollision(leftCollider, rightCollider);
								}
							}
						}
					}
				}
			}
		}
	}

	void CollisionManager::ColliderCollision(Collider* Left, Collider* Right)
	{
		CollisionID id = {};
		id.left        = Left->GetID();
		id.right       = Right->GetID();

		if (!mCollisionMap.contains(id.id))
		{
			mCollisionMap[id.id] = false;
		}

		if (Intersaect(Left, Right))
		{
			if (mCollisionMap[id.id])
			{
				Left->OnCollisionStay(Right);
				Right->OnCollisionStay(Left);
			}
			else
			{
				Left->OnCollisionEnter(Right);
				Right->OnCollisionEnter(Left);
				mCollisionMap[id.id] = true;
			}
		}
		else
		{
			if (mCollisionMap[id.id])
			{
				Left->OnCollisionExit(Right);
				Right->OnCollisionExit(Left);

				mCollisionMap[id.id] = false;
			}
		}
	}

	bool CollisionManager::Intersaect(Collider* Left, Collider* Right)
	{
		Transform* lTransform = Left->GetOwner()->GetTransform();
		Transform* rTransform = Right->GetOwner()->GetTransform();

		Vector2 lPos = lTransform->GetPosition();
		Vector2 rPos = rTransform->GetPosition();

		Vector2 lSize = Left->GetSize();
		Vector2 rSize = Right->GetSize();

		if (fabs((lPos.X + lSize.X / 2.f) - (rPos.X + rSize.X / 2.f)) < fabs((lSize.X + rSize.X) / 2.f) &&
			fabs((lPos.Y + lSize.Y / 2.f) - (rPos.Y + rSize.Y / 2.f)) < fabs((lSize.Y + rSize.Y) / 2.f))
		{
			return true;
		}

		return false;
	}
>>>>>>> 05220025e134bab7820fcdee72603266979b8482
}
