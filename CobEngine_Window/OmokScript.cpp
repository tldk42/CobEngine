#include "OmokScript.h"

#include "CobObject.h"
#include "CobResources.h"
#include "CobInput.h"
#include "CobSpriteRenderer.h"
// #include "../CobEngine_Source/CobInput.h"
// #include "../CobEngine_Source/CobSpriteRenderer.h"

namespace Cob::Omok
{
	OmokScript::OmokScript()
		: bIsWhiteTurn(false),
		  mMap{{EMapState::Empty},}
	{
	}

	OmokScript::~OmokScript()
	{
	}

	void OmokScript::Initialize()
	{
		Script::Initialize();
	}

	void OmokScript::Update()
	{
		Script::Update();


		if (Input::GetKeyDown(EKeyCode::LButton))
		{
			Math::Vector2 mousePos = Input::GetMousePosition();


			// 1. Find Nearest coordinate in map
			if (CanBeDraw(mousePos))
			{
				// 2. DrawCircle(x, y);
				Object*         doll              = Object::Instantiate<Object>(ELayerType::Player, mousePos);
				SpriteRenderer* dollImage         = doll->AddComponent<SpriteRenderer>();
				Texture*        backgroundTexture = Resources::Find<Texture>(L"Cat");

				dollImage->SetSize({.2f, .2f});
				dollImage->SetTexture(backgroundTexture);
				doll->GetComponent<Transform>()->SetPosition(mousePos);
			}
		}
	}

	void OmokScript::LateUpdate()
	{
		Script::LateUpdate();
	}

	void OmokScript::Render(HDC Hdc)
	{
		Script::Render(Hdc);
	}

	bool OmokScript::CanBeDraw(const Vector2& Coord) const
	{
		Vector2 size = Coord / MAX_WIDTH;
		return mMap[(int)size.X][(int)size.Y] == EMapState::Empty;
	}
}
