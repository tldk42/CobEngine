#pragma once
#include "CommonInclude.h"

namespace Cob
{
	/**
	 * \brief 기본 개체 클래스
	 * 고유 아이디를 가짐
	 */
	class Entity
	{
	public:
		Entity();
		virtual ~Entity();

		FORCEINLINE void SetName(const std::wstring& Name) { mName = Name; }
		FORCEINLINE const std::wstring& GetName() { return mName; }

	protected:
		/** 개체의 고유 아이디 */
		std::wstring mName;
	};
}
