#pragma once
#include "CommonInclude.h"

namespace Cob
{
	/** 키의 세부 상태 */
	enum class EKeyState
	{
		None,
		Down,
		Pressed,
		Up
	};

	/** 키보드로 입력될 수 있는 키 목록 */
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
		LButton,
		MButton,
		RButton,
		End
	};

	struct Key
	{
		EKeyCode  keyCode;
		EKeyState state;
		bool      bPressed;
	};

	class Input
	{
	public:
		static void Initialize();
		static void Update();

		FORCEINLINE static bool GetKeyDown(EKeyCode Key)
		{
			return Keys[static_cast<UINT>(Key)].state == EKeyState::Down;
		}

		FORCEINLINE static bool GetKeyUp(EKeyCode Key)
		{
			return Keys[static_cast<UINT>(Key)].state == EKeyState::Up;
		}

		FORCEINLINE static bool GetKey(EKeyCode Key)
		{
			return Keys[static_cast<UINT>(Key)].state == EKeyState::Pressed;
		}

		FORCEINLINE static Math::Vector2 GetMousePosition()
		{
			return MousePosition;
		}

	private:
		/** 키 배열에 순서대로 모든 키구조체 정보를 채워 넣는다. */
		static void CreateKeys();
		/** 모든 키배열에 대해 상태를 업데이트한다. */
		static void UpdateKeys();
		static void ClearKeys();
		/** InKey에 대해 상태를 업데이트한다. */
		static void UpdateKey(Key& InKey);
		/** InKey가 눌렸는지 반환 */
		static bool IsKeyDown(EKeyCode InKey);

		static void UpdateKeyDown(Key& InKey);
		static void UpdateKeyUp(Key& InKey);

		static void GetMousePositionWindow();

	private:
		static std::vector<Key> Keys;
		static Math::Vector2    MousePosition;
	};
}
