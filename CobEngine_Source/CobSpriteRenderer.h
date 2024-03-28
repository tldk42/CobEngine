#pragma once
#include "CobComponent.h"

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

		void LoadImage_Implement(const std::wstring& Path);

	private:
		Gdiplus::Image* mImage;
		UINT mWidth;
		UINT mHeight;
	};
}
