
#pragma once

#include "PCH.h"

namespace Test
{
	class Game : public KatanaEngine::Game
	{

	public:

		Game();

		virtual ~Game() { }

		virtual std::string GetName() const { return "Test"; }

	};
}