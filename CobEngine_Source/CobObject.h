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
	enum class EObjectState
	{
		Active,
		Paused,
		Dead,
		End
	};

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

			mComponents[static_cast<UINT>(comp->GetType())] = comp;

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
				component = dynamic_cast<T*>(comp);
				if (component)
				{
					break;
				}
			}

			return component;
		}


		/**
		 * \brief Ư�� ���̾ ������Ʈ�� �߰�
		 * \tparam T ������Ʈ �Ļ� Ŭ����
		 * \param Type ���̾� Ÿ��
		 * \return �߰� �� ������Ʈ
		 */
		template <typename T>
		static T* Instantiate(const ELayerType Type)
		{
			T* object = new T;

			object->SetLayerType(Type);
			Scene* activeScene = SceneManager::GetActiveScene();
			Layer* layer       = activeScene->GetLayer(Type);
			layer->AddObject(object);

			return object;
		}

		template <typename T>
		static T* Instantiate(const ELayerType Type, const Vector2& Position)
		{
			T* object = new T;

			object->SetLayerType(Type);
			Scene* activeScene = SceneManager::GetActiveScene();
			Layer* layer       = activeScene->GetLayer(Type);
			layer->AddObject(object);

			Transform* tr = object->template GetComponent<Transform>();
			tr->SetPosition(Position);

			return object;
		}

		static void DontDestroyOnLoad(Object* Object)
		{
			Scene* activeScene = SceneManager::GetActiveScene();
			if (activeScene)
			{
				activeScene->DeleteObject(Object);
			}

			Scene* dontDestroyOnLoad = SceneManager::GetDontDestroyOnLoad();
			dontDestroyOnLoad->AddGameObject(Object, Object->GetLayerType());
		}

		Transform* GetTransform() const;

		FORCEINLINE bool IsActive() const { return mState == EObjectState::Active; }
		FORCEINLINE bool IsDead() const { return mState == EObjectState::Dead; }

		FORCEINLINE EObjectState GetState() const { return mState; }
		FORCEINLINE void         SetState(const EObjectState NewState) { mState = NewState; }

		FORCEINLINE ELayerType GetLayerType() const { return mLayerType; }
		FORCEINLINE void       SetLayerType(const ELayerType InLayerType) { mLayerType = InLayerType; }

	private:
		void InitializeTransform();

	protected:
		/** �� ������Ʈ�� �����ϰ� �ִ� ������Ʈ�� */
		std::vector<Component*> mComponents;
		EObjectState            mState;
		ELayerType              mLayerType;
	};
}
