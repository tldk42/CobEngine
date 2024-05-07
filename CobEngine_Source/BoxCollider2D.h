#pragma once
#include "CobCollider.h"

namespace Cob
{
	class BoxCollider2D : public Collider
	{
	public:
		BoxCollider2D();
		~BoxCollider2D() override;

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC Hdc) override;

<<<<<<< HEAD
	private:
		Math::Vector2 mSize;
=======
>>>>>>> 05220025e134bab7820fcdee72603266979b8482
	};
}
