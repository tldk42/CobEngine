#pragma once
#include "CobEntity.h"

namespace Cob
{
	/**
	 * \brief 리소스 베이스클래스
	 */
	class Resource abstract : public Entity
	{
	public:
		Resource(EResourceType ResourceType);
		virtual ~Resource();

		virtual HRESULT Load(const std::wstring& Path) = 0;

		/** 이 리소스의 상대경로 반환 */
		FORCEINLINE const std::wstring& GetPath() { return mPath; }
		/** 이 리소스의 상대경로 지정 */
		FORCEINLINE void SetPath(const std::wstring& Path) { mPath = Path; }

	private:
		const EResourceType mResourceType;
		std::wstring mPath;
	};
}
