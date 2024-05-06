#pragma once
#include "CobComponent.h"

namespace Cob
{
	class Collider : public Component
	{
	public:
		Collider();
		~Collider() override;

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC Hdc) override;

		FORCEINLINE Math::Vector2 GetOffset() const { return mOffset; }
		FORCEINLINE void          SetOffset(const Math::Vector2 InOffset) { mOffset = InOffset; }

	protected:
		Math::Vector2 mOffset;
		
	};
}
