#pragma once
#include "CobScript.h"

namespace Cob
{
	namespace Omok
	{
		enum class EMapState
		{
			Empty,
			White,
			Black,
			Hover
		};

		class OmokScript : public Script
		{
		public:
			OmokScript();
			~OmokScript();

			void Initialize() override;
			void Update() override;
			void LateUpdate() override;
			void Render(HDC Hdc) override;

		private:
			bool CanBeDraw(const Math::Vector2& Coord) const;

		private:
			enum
			{
				MAX_WIDTH = 18
			};

			bool      bIsWhiteTurn;
			EMapState mMap[MAX_WIDTH][MAX_WIDTH];
		};
	}
}
