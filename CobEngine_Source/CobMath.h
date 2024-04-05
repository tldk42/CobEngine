#pragma once


namespace Cob::Math
{
	struct Vector2
	{
	public:
		static Vector2 ONE;
		static Vector2 ZERO;

		float X;
		float Y;

		Vector2()
			: X(0.f),
			  Y(0.f)
		{
		}

		Vector2(const float InX, const float InY)
			: X(InX),
			  Y(InY)
		{
		}

		Vector2 operator+(const Vector2& Other) const
		{
			return {X + Other.X, Y + Other.Y};
		}

		Vector2 operator-(const Vector2& Other) const
		{
			return {X - Other.X, Y - Other.Y};
		}

		Vector2 operator/(const float Value) const
		{
			return {X / Value, Y / Value};
		}

		Vector2 operator*(const float Value) const
		{
			return {X * Value, Y * Value};
		}
	};
}
