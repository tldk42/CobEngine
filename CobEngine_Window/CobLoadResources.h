#pragma once

#include "../CobEngine_Source/CobResources.h"
#include "../CobEngine_Source/CobTexture.h"

namespace Cob
{
	void LoadResources()
	{
		Resources::Load<Texture>(L"Chicken", L"../Resource/img/Chicken.bmp");
		Resources::Load<Texture>(L"Map", L"../Resource/img/map/map_pure.png");
		Resources::Load<Texture>(L"PacMan", L"../Resource/img/pacman/1.png");
		Resources::Load<Texture>(L"Cat", L"../Resource/img/snowball.bmp");
		Resources::Load<Texture>(L"Maple_VFX", L"../Resource/ezgif.com-gif-maker.png");
	}
}
