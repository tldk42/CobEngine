#pragma once
#include "../CobEngine_Source/CobScene.h"

namespace Cob
{
	class TitleScene : public Scene
	{
	public:
		TitleScene();
		~TitleScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC Hdc) override;

	private:
	};
}
