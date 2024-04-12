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

		void AttackEffect();

	private:
		void SitDown();
		void Move();

	private:
		class Animator* mAnimator;

		EPlayerState mPlayerState;
	};
}
