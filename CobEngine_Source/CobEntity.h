#pragma once
#include "CommonInclude.h"

namespace Cob
{
	class Entity
	{
	public:
		Entity();
		virtual ~Entity();

		FORCEINLINE void SetName(const std::wstring& Name) { mName = Name; }
		FORCEINLINE const std::wstring& GetName() { return mName; }

	protected:
		/** ��ü�� ���� ���̵� */
		std::wstring mName;
	};
}
