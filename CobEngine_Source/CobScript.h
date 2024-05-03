#pragma once
#include "CobComponent.h"

namespace Cob
{
	class Script : public Component
	{
	public:
		Script();
		~Script();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC Hdc) override;

		virtual void OnCollisionEnter(class Collider* Other);
		virtual void OnCollisionStay(Collider* Other);
		virtual void OnCollisionExit(Collider* Other);

	private:
	};
}
