#pragma once
#include "CobEntity.h"

namespace Cob
{
	/**
	 * \brief ���ҽ� ���̽�Ŭ����
	 */
	class Resource abstract : public Entity
	{
	public:
		Resource(EResourceType ResourceType);
		virtual ~Resource();

		virtual HRESULT Load(const std::wstring& Path) = 0;

		/** �� ���ҽ��� ����� ��ȯ */
		FORCEINLINE const std::wstring& GetPath() { return mPath; }
		/** �� ���ҽ��� ����� ���� */
		FORCEINLINE void SetPath(const std::wstring& Path) { mPath = Path; }

	private:
		const EResourceType mResourceType;
		std::wstring mPath;
	};
}
