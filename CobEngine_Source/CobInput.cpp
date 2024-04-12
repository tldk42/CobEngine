#include "CobInput.h"
#include "CobApplication.h"

extern Cob::Application application;

namespace Cob
{
	std::vector<Key> Input::Keys          = {};
	Vector2          Input::MousePosition = Vector2::ZERO;

	int ASCII[static_cast<UINT>(EKeyCode::End)] =
	{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',
		VK_LEFT, VK_RIGHT, VK_DOWN, VK_UP,
		VK_LBUTTON, VK_MBUTTON, VK_RBUTTON
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

			Keys.push_back(key);
		}
	}

	void Input::UpdateKeys()
	{
		std::ranges::for_each(Keys, [](Key& InKey)
		{
			UpdateKey(InKey);
		});
	}

	void Input::UpdateKey(Key& InKey)
	{
		if (GetFocus())
		{
			IsKeyDown(InKey.KeyCode) ? UpdateKeyDown(InKey) : UpdateKeyUp(InKey);

			GetMousePositionWindow();
		}
		else
		{
			ClearKeys();
		}
	}

	bool Input::IsKeyDown(EKeyCode InKey)
	{
		// 0x8000 은 현재 키가 눌려진 상태
		return GetAsyncKeyState(ASCII[static_cast<UINT>(InKey)]) & 0x8000;
	}

	void Input::UpdateKeyDown(Key& InKey)
	{
		InKey.State = InKey.bPressed ? EKeyState::Pressed : EKeyState::Down;

		InKey.bPressed = true;
	}

	void Input::UpdateKeyUp(Key& InKey)
	{
		InKey.State = InKey.bPressed ? EKeyState::Up : EKeyState::None;

		InKey.bPressed = false;
	}

	void Input::GetMousePositionWindow()
	{
		POINT mousePos;

		// 마우스 포인터위치 저장
		GetCursorPos(&mousePos);

		// 저장된 포인터 위치를 클라이언트 영역 좌표로 변환
		ScreenToClient(application.GetHwnd(), &mousePos);

		MousePosition.X = mousePos.x;
		MousePosition.Y = mousePos.y;
	}

	void Input::ClearKeys()
	{
		for (Key& key : Keys)
		{
			switch (key.State)
			{
			case EKeyState::Down:
			case EKeyState::Pressed:
				key.State = EKeyState::Up;
				break;
			case EKeyState::Up:
				key.State = EKeyState::None;
				break;
			case EKeyState::None:
				break;
			}

			key.bPressed = false;
		}
	}
}
