#pragma once
#include "CobScript.h"

namespace Cob
{
	class PlayerScript : public Script
	{
	public:
		PlayerScript();
		~PlayerScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC Hdc) override;

		void OnCollisionEnter( Collider* Other) override;
		void OnCollisionStay( Collider* Other) override;
		void OnCollisionExit( Collider* Other) override;


	private:
		void SitDown();
		void Move();

	private:
		class Animator* mAnimator;

		EPlayerState mPlayerState;
	};
}
