#pragma once


namespace Cob::Math
{
	struct Vector2
	{
	public:
		static Vector2 One;
		static Vector2 Zero;

		float x;
		float y;

		Vector2()
			: x(0.f),
			  y(0.f)
		{
		}

		Vector2(float _x, float _y)
			: x(_x),
			  y(_y)
		{
		}
	};
}
