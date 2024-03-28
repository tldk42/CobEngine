#pragma once
#include "CobEntity.h"

namespace Cob
{
	class Resource abstract : public Entity
	{
	public:
		Resource(EResourceType ResourceType);
		virtual ~Resource();

		virtual HRESULT Load(const std::wstring& Path) = 0;

		FORCEINLINE const std::wstring& GetPath() { return mPath; }
		FORCEINLINE void SetPath(const std::wstring& Path) { mPath = Path; }

	private:
		const EResourceType mResourceType;
		std::wstring mPath;
	};
}
