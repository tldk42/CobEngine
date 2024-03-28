#pragma once
#include "CommonInclude.h"
#include "CobComponent.h"
#include "CobLayer.h"
#include "CobSceneManager.h"
#include "CobTransform.h"

namespace Cob
{
	class Scene;
}

namespace Cob
{
	/**
	 * \brief 엔진의 Base Object (언리얼의 Actor)
	 */
	class Object
	{
	public:
		Object();
		virtual ~Object();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC Hdc);

		/**
		 * \brief 이 오브젝트에 컴포넌트를 추가한다.
		 * \tparam T 컴포넌트 타입
		 * \return 추가된 컴포넌트
		 */
		template <typename T>
		T* AddComponent()
		{
			T* comp = new T;
			comp->Initialize();
			comp->SetOwner(this);
			mComponents.push_back(comp);

			return comp;
		}

		/**
		 * \brief 가지고 있는 컴포넌트배열에서 조건을 만족하는 가장 첫 컴포넌트를 반환한다.
		 * \tparam T 컴포넌트 타입
		 * \return 반환될 컴포넌트
		 */
		template <typename T>
		T* GetComponent()
		{
			T* component = nullptr;

			for (Component* comp : mComponents)
			{
				component = static_cast<T*>(comp);
				if (component)
				{
					break;
				}
			}

			return component;
		}

		template <typename T>
		static T* Instantiate(const ELayerType Type)
		{
			T* object = new T;
			Scene* activeScene = SceneManager::GetActiveScene();
			Layer* layer = activeScene->GetLayer(Type);
			layer->AddObject(object);

			return object;
		}

		template <typename T>
		static T* Instantiate(const ELayerType Type, const Vector2& Position)
		{
			T* object = new T;
			Scene* activeScene = SceneManager::GetActiveScene();
			Layer* layer = activeScene->GetLayer(Type);
			layer->AddObject(object);

			Transform* tr = object->template GetComponent<Transform>();
			tr->SetPosition(Position);

			return object;
		}

	private:
		void InitializeTransform();

	private:
		/** 이 오브젝트가 소유하고 있는 컴포넌트들 */
		std::vector<Component*> mComponents;
	};
}
