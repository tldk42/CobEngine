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
		//�Ķ� �귯�� ����
		HBRUSH blueBrush
			= CreateSolidBrush(RGB(255, 0, 255));

		// �Ķ� �귯�� DC�� ���� �׸��� ��� �귯�� ��ȯ�� ��ȯ
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
