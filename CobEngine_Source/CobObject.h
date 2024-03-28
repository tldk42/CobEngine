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
	 * \brief ������ Base Object (�𸮾��� Actor)
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
		 * \brief �� ������Ʈ�� ������Ʈ�� �߰��Ѵ�.
		 * \tparam T ������Ʈ Ÿ��
		 * \return �߰��� ������Ʈ
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
		 * \brief ������ �ִ� ������Ʈ�迭���� ������ �����ϴ� ���� ù ������Ʈ�� ��ȯ�Ѵ�.
		 * \tparam T ������Ʈ Ÿ��
		 * \return ��ȯ�� ������Ʈ
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
		/** �� ������Ʈ�� �����ϰ� �ִ� ������Ʈ�� */
		std::vector<Component*> mComponents;
	};
}
