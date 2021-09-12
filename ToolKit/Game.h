#pragma once

#include "KatanaEngine.h"

namespace KatanaEngine
{
	namespace TK
	{
		class Game : public KatanaEngine::Game
		{
		public:

			Game();
			virtual ~Game() { }

			virtual std::string GetName() const { return "Test"; }

		private:

			KatanaEngine::ScreenManager *m_pScreenManager = nullptr;
		};
	}
}