#pragma once

namespace Cob
{
	enum class ELayerType
	{
		None,
		Background,
		Player,
		Max = 16
	};

	enum class EResourceType
	{
		Texture,
		AudioClip,
		Prefab,
		End
	};
}
