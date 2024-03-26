#include "CobSpriteRenderer.h"

#include "CobObject.h"
#include "CobTransform.h"

namespace Cob
{
	SpriteRenderer::SpriteRenderer()
	{
	}

	SpriteRenderer::~SpriteRenderer()
	{
	}

	void SpriteRenderer::Initialize()
	{
		Component::Initialize();
	}

	void SpriteRenderer::Update()
	{
		Component::Update();
	}

	void SpriteRenderer::LateUpdate()
	{
		Component::LateUpdate();
	}

	void SpriteRenderer::Render(HDC Hdc)
	{
		//파랑 브러쉬 생성
		HBRUSH blueBrush
			= CreateSolidBrush(RGB(255, 0, 255));

		// 파랑 브러쉬 DC에 선택 그리고 흰색 브러쉬 반환값 반환
		HBRUSH oldBrush = (HBRUSH)SelectObject(Hdc, blueBrush);

		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(rand() % 255, rand() % 255, rand() % 255));
		HPEN oldPen = (HPEN)SelectObject(Hdc, redPen);
		SelectObject(Hdc, oldPen);

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Rectangle(Hdc, tr->GetX(), tr->GetY()
		          , 100 + tr->GetX(), 100 + tr->GetY());

		SelectObject(Hdc, oldBrush);
		DeleteObject(blueBrush);
		DeleteObject(redPen);
	}
}
