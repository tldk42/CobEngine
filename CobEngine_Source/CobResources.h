#pragma once
#include "CobResource.h"

namespace Cob
{
	class Resources
	{
	public:
		template <typename T>
		static T* Find(const std::wstring& Key)
		{
			if (mResources.contains(Key))
			{
				return dynamic_cast<T*>(mResources[Key]);
			}

			return nullptr;
		}

		template <typename T>
		static T* Load(const std::wstring& Key, const std::wstring& Path)
		{
			T* resource = Resources::Find<T>(Key);

			if (!resource)
			{
				resource = new T;

				if (!FAILED(resource->Load(Path)))
				{
					resource->SetName(Key);
					resource->SetPath(Path);
					mResources.insert({Key, resource});
				}
			}

			return resource;
		}

	private:
		static std::map<std::wstring, Resource*> mResources;
	};
}
