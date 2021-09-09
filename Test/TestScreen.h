
#pragma once

#include "PCH.h"

using namespace KatanaEngine;
using namespace KatanaEngine::GUI;
using namespace KatanaEngine::PE;

namespace Test
{

	class TestScreen : public Screen
	{

	public:

		TestScreen(ParticleManager *pParticleManager) { }
		virtual ~TestScreen();

		virtual void LoadContent(ResourceManager *pResourceManager);

		virtual void HandleInput(const InputState *pInput);

		virtual void Update(const GameTime *pGameTime);

		virtual void Draw(SpriteBatch *pSpriteBatch);

	private:

		Texture *m_pCharacterTexture = nullptr;
		Animation *m_pCharacterAnimation = nullptr;

	};
}