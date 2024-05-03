#pragma once

namespace Cob
{
	enum class ELayerType
	{
		None,
		Background,
		Player,
		Particle,
		Animal,
		Max = 16
	};

	enum class EResourceType
	{
		Texture,
		AudioClip,
		Prefab,
		End,
		Animation
	};

	enum class ETextureType
	{
		None,
		Bmp,
		Png,
		Jpg
	};

	enum class EComponentType
	{
		Transform,
		Collider,
		Script,
		SpriteRenderer,
		Camera,
		Animator,
		End
	};

	enum class EPlayerState
	{
		Sleep,
		SitDown,
		Walk,
		Attack
	};
}
