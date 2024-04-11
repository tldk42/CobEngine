#pragma once
#include "CobObject.h"

namespace Cob
{
	class Cat : public Object
	{
	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC Hdc) override;
	};
}
