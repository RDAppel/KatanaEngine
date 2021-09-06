
#include "PCH.h"

namespace Test
{
	Game::Game()
	{
		SetScreenResolution(1600, 900);
		SetFullScreen(false);

		InitializeScreenManager();
		//InitializeParticleManager();

		SetResourceDirectory("..\\Test\\Content\\");

		GetScreenManager()->AddScreen(new TestScreen);

		SetClearColor(Color(45.0f / 255, 45.0f / 255, 50.0f / 255));
	}
}