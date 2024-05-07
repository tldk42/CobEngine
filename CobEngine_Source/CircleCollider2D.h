#pragma once
#include "CobCollider.h"

namespace Cob
{
	class CircleCollider2D : public Collider
	{
	public:
		CircleCollider2D();
		~CircleCollider2D() override;

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC Hdc) override;

	private:
		float mRadius;
	};
}
