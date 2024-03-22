#include "CobInput.h"

namespace Cob
{
	std::vector<Key> Input::mKeys = {};

	int ASCII[static_cast<UINT>(EKeyCode::End)] =
	{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',
		VK_LEFT, VK_RIGHT, VK_DOWN, VK_UP,
	};

	void Input::Initialize()
	{
		CreateKeys();
	}

	void Input::Update()
	{
		UpdateKeys();
	}

	void Input::CreateKeys()
	{
		for (size_t i = 0; i < static_cast<UINT>(EKeyCode::End); i++)
		{
			Key key = {static_cast<EKeyCode>(i), EKeyState::None, false};

			mKeys.push_back(key);
		}
	}

	void Input::UpdateKeys()
	{
		std::ranges::for_each(mKeys, [](Key& InKey)
		{
			UpdateKey(InKey);
		});
	}

	void Input::UpdateKey(Key& InKey)
	{
		if (IsKeyDown(InKey.keyCode))
		{
			UpdateKeyDown(InKey);
		}
		else
		{
			UpdateKeyUp(InKey);
		}
	}

	bool Input::IsKeyDown(EKeyCode InKey)
	{
		return GetAsyncKeyState(ASCII[static_cast<UINT>(InKey)]) & 0x8000;
	}

	void Input::UpdateKeyDown(Key& InKey)
	{
		InKey.state = InKey.bPressed ? EKeyState::Pressed : EKeyState::Down;

		InKey.bPressed = true;
	}

	void Input::UpdateKeyUp(Key& InKey)
	{
		InKey.state = InKey.bPressed ? EKeyState::Up : EKeyState::None;

		InKey.bPressed = false;
	}
}
