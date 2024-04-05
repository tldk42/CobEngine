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

		void OnEnter() override;
		void OnExit() override;

	private:
		class Player* mPlayer;
	};
}
