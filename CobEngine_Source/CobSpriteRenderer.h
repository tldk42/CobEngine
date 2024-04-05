#pragma once
#include "CobComponent.h"
#include "CobTexture.h"

namespace Cob
{
	class SpriteRenderer : public Component
	{
	public:
		SpriteRenderer();
		~SpriteRenderer();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC Hdc) override;

#pragma region Setter
		FORCEINLINE void SetTexture(Texture* InTexture) { mTexture = InTexture; }
		FORCEINLINE void SetSize(const Math::Vector2 InSize) { mSize = InSize; }
#pragma endregion

	private:
		Texture* mTexture;
		Math::Vector2 mSize;
	};
}
