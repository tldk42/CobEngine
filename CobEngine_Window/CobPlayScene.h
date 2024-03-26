#pragma once
#include "../CobEngine_Source/CobScene.h"

namespace Cob
{
	class PlayScene : public Scene
	{
	public:
		PlayScene();
		~PlayScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC Hdc) override;

	private:
	};
}
