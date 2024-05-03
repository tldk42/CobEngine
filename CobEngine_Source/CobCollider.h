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

		void OnCollisionEnter(Collider* Other);
		void OnCollisionStay(Collider* Other);
		void OnCollisionExit(Collider* Other);

	public:
#pragma region Getter & Setter
		FORCEINLINE Math::Vector2 GetSize() const { return mSize; }
		FORCEINLINE void          SetSize(const Math::Vector2& InSize) { mSize = InSize; }

		FORCEINLINE Math::Vector2 GetOffset() const { return mOffset; }
		FORCEINLINE void          SetOffset(const Math::Vector2& InOffset) { mOffset = InOffset; }

		FORCEINLINE UINT32 GetID() const { return mID; }
		FORCEINLINE void   SetDebugColor(const COLORREF InColor) { mDebugColor = InColor; }
#pragma endregion
		void SetInitValue(const Math::Vector2& Offset, const Math::Vector2& Size);

	protected:
		static UINT CollisionID;

		UINT32        mID;
		Math::Vector2 mOffset;
		Math::Vector2 mSize;

		COLORREF mDebugColor;
	};
}
