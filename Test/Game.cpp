
#include "PCH.h"

using namespace KatanaEngine::PE;

namespace Test
{

	Game::Game()
	{
		SetScreenResolution(1600, 900);
		SetFullScreen(false);

		m_pScreenManager = InitializeScreenManager();
		m_pParticleManager = InitializeParticleManager();

		SetResourceDirectory("..\\Test\\Content\\");

		TestScreen *pScreen = new TestScreen(m_pParticleManager);
		m_pScreenManager->AddScreen(pScreen);

		SetClearColor(Color(45.0f / 255, 45.0f / 255, 50.0f / 255));
	}

	ParticleManager *Game::InitializeParticleManager()
	{
		ParticleManager *pParticleManager = new ParticleManager;
		bool added = AddService(pParticleManager);

		if (added) return pParticleManager;

		delete pParticleManager;
		return nullptr;
	}
}