#pragma once
#include "../CobEngine_Source/CobMath.h"

namespace Cob
{
	using namespace Math;

	class Player_Base
	{
	public:
		Player_Base();
		~Player_Base();

		void Initialize();

	private:
		Vector2 Position;
	};
}
