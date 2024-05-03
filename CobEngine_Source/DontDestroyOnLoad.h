#pragma once
#include "CobScene.h"

namespace Cob
{
	class DontDestroyOnLoad : public Scene
	{

	public:
		DontDestroyOnLoad();
		~DontDestroyOnLoad();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC Hdc) override;
		void Destroy() override;

		void OnEnter() override;
		void OnExit() override;
	};
}
