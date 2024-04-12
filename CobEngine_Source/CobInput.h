#pragma once
#include "CommonInclude.h"

namespace Cob
{
	/** Ű�� ���� ���� */
	enum class EKeyState
	{
		None,
		Down,
		Pressed,
		Up
	};

	/** Ű����� �Էµ� �� �ִ� Ű ��� */
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
		EKeyCode  KeyCode;
		EKeyState State;
		bool      bPressed;
	};

	class Input
	{
	public:
		static void Initialize();
		static void Update();

#pragma region Getter
		FORCEINLINE static bool GetKeyDown(EKeyCode Key)
		{
			return Keys[static_cast<UINT>(Key)].State == EKeyState::Down;
		}

		FORCEINLINE static bool GetKeyUp(EKeyCode Key)
		{
			return Keys[static_cast<UINT>(Key)].State == EKeyState::Up;
		}

		FORCEINLINE static bool GetKey(EKeyCode Key)
		{
			return Keys[static_cast<UINT>(Key)].State == EKeyState::Pressed;
		}

		FORCEINLINE static Math::Vector2 GetMousePosition()
		{
			return MousePosition;
		}
#pragma endregion

	private:
#pragma region Input State
		/** Ű �迭�� ������� ��� Ű����ü ������ ä�� �ִ´�. */
		static void CreateKeys();
		/** ��� Ű�迭�� ���� ���¸� ������Ʈ�Ѵ�. */
		static void UpdateKeys();
		/** InKey�� ���� ���¸� ������Ʈ�Ѵ�. */
		static void UpdateKey(Key& InKey);
		/** InKey�� ���ȴ��� ��ȯ */
		static bool IsKeyDown(EKeyCode InKey);

		static void UpdateKeyDown(Key& InKey);
		static void UpdateKeyUp(Key& InKey);

		static void GetMousePositionWindow();
		static void ClearKeys();
#pragma endregion

	private:
		static std::vector<Key> Keys;
		static Math::Vector2    MousePosition;
	};
}
