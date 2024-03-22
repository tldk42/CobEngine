#include "CobInput.h"

namespace Cob
{
	std::vector<Key> Input::mKeys = {};

	int ASCII[static_cast<UINT>(EKeyCode::End)] =
	{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',
	};

	void Input::Initialize()
	{
		for (size_t i = 0; i < (UINT)EKeyCode::End; i++)
		{
			Key key = {};
			key.bPressed = false;
			key.state = EKeyState::None;
			key.keyCode = (EKeyCode)i;

			mKeys.push_back(key);
		}
	}

	void Input::Update()
	{
		for (size_t i = 0; i < mKeys.size(); i++)
		{
			//Ű�� ���ȴ�
			if (GetAsyncKeyState(ASCII[i]) & 0x8000)
			{
				if (mKeys[i].bPressed == true)
					mKeys[i].state = EKeyState::Pressed;
				else
					mKeys[i].state = EKeyState::Down;

				mKeys[i].bPressed = true;
			}
			else // Ű�� �ȴ��ȴ�.
			{
				if (mKeys[i].bPressed == true)
					mKeys[i].state = EKeyState::Up;
				else
					mKeys[i].state = EKeyState::None;

				mKeys[i].bPressed = false;
			}
		}
	}
}
