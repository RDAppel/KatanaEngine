
#include "PCH.h"

namespace Test
{
	Game::Game()
	{
		SetScreenResolution(1600, 900);
		SetFullScreen(false);

		m_pScreenManager = InitializeScreenManager();
		//InitializeParticleManager();

		SetResourceDirectory("..\\Test\\Content\\");

		m_pScreenManager->AddScreen(new TestScreen);

		SetClearColor(Color(45.0f / 255, 45.0f / 255, 50.0f / 255));
	}
}