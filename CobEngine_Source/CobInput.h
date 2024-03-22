#pragma once
#include "CommonInclude.h"

namespace Cob
{
	enum class EKeyState
	{
		None,
		Down,
		Pressed,
		Up
	};

	enum class EKeyCode
	{
		Q,
		W,
		E,
		R,
		T,
		Y,
		U,
		I,
		O,
		P,
		A,
		S,
		D,
		F,
		G,
		H,
		J,
		K,
		L,
		Z,
		X,
		C,
		V,
		B,
		N,
		M,
		Left,
		Right,
		Down,
		Up,
		End
	};

	struct Key
	{
		EKeyCode keyCode;
		EKeyState state;
		bool bPressed;
	};

	class Input
	{
	public:
		static void Initialize();
		static void Update();

		static bool GetKeyDown(EKeyCode Key)
		{
			return mKeys[static_cast<UINT>(Key)].state == EKeyState::Down;
		}

		static bool GetKeyUp(EKeyCode Key)
		{
			return mKeys[static_cast<UINT>(Key)].state == EKeyState::Up;
		}

		static bool GetKey(EKeyCode Key)
		{
			return mKeys[static_cast<UINT>(Key)].state == EKeyState::Pressed;
		}

	private:
		static void CreateKeys();
		static void UpdateKeys();
		static void UpdateKey(Key& InKey);
		static bool IsKeyDown(EKeyCode InKey);
		static void UpdateKeyDown(Key& InKey);
		static void UpdateKeyUp(Key& InKey);

	private:
		static std::vector<Key> mKeys;
	};
}
