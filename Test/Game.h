
#pragma once

#include "PCH.h"

using namespace KatanaEngine::PE;

namespace Test
{

	class Game : public KatanaEngine::Game
	{

	public:

		Game();

		virtual ~Game() { }

		virtual std::string GetName() const { return "Test"; }

		virtual ParticleManager *InitializeParticleManager();

	private:

		KatanaEngine::ScreenManager *m_pScreenManager = nullptr;

		ParticleManager *m_pParticleManager = nullptr;

	};
}