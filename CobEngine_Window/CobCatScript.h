#pragma once
#include "CobScript.h"

namespace Cob
{
	class Transform;

	enum class ECatWalkDirection
	{
		Left,
		Right,
		Up,
		Down,
		End
	};

	enum class ECatState
	{
		Idle,
		Walk,
		LayDown,
		SitDown,
		Attack
	};

	class CatScript : public Script
	{
	public:
		CatScript();
		~CatScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC Hdc) override;

	private:
		void SitDown();
		void Move();
		void LayDown();

		void PlayWalkAnimationByDirection(ECatWalkDirection Direction);
		void Translate(Transform* Transform);

	private:
		class Animator* mAnimator;

		float mTime;

		ECatState         mState;
		ECatWalkDirection mWalkDirection;
	};
}
