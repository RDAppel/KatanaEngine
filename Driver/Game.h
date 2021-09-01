#pragma once

#include "KatanaEngine.h"

namespace Driver
{
	class Game : public KatanaEngine::Game
	{

	public:

		Game()
		{
			SetScreenResolution(1600, 900);
			SetFullScreen(false);

			//InitializeScreenManager();
			//InitializeParticleManager();

			SetResourceDirectory("..\\KatanaEngine\\Content\\");
		}

		virtual ~Game() { }

		virtual std::string GetName() const { return "Driver"; }
	};
}