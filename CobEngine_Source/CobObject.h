#pragma once
#include "CommonInclude.h"
#include "CobComponent.h"

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

	private:
		/** �� ������Ʈ�� �����ϰ� �ִ� ������Ʈ�� */
		std::vector<Component*> mComponents;
	};
}
