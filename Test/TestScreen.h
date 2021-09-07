
#pragma once

#include "PCH.h"

using namespace KatanaEngine;
using namespace KatanaEngine::GUI;

namespace Test
{

	class TestScreen : public Screen
	{

	public:

		TestScreen(ParticleManager *pParticleManager) { m_pParticleManager = pParticleManager; }
		virtual ~TestScreen();

		virtual void LoadContent(ResourceManager *pResourceManager);

		virtual void HandleInput(const InputState *pInput);

		virtual void Update(const GameTime *pGameTime);

		virtual void Draw(SpriteBatch *pSpriteBatch);

		enum class Demo
		{
			LINE,
			COLOR,
			TWO_LINE,
			THREE_LINE,
			THREE_LINE_WPT,
			QUADRATIC,
			FOUR_LINES,
			FOUR_LINES_WPT,
			FOUR_LINES_W1LERP,
			FOUR_LINES_W1LERP_WPT,
			FOUR_LINES_W2LERP,
			FOUR_LINES_W2LERP_WPT,
			CUBIC,
			CUBIC_RM_LINES,
			PARTICLES_ONLY,
			END
		};

	private:

		Theme *m_pTheme = nullptr;
		Panel *m_pPanel = nullptr;
		Toggle *m_pToggle = nullptr;
		Slider *m_pSlider = nullptr;
		ComponentCollection *m_pComponents = nullptr;

		static const uint8_t NUM_TEXTURES = 4;
		Texture *m_pParticleTextures[NUM_TEXTURES] = { };
		ParticleManager *m_pParticleManager = nullptr;
		ParticleEmitter *m_pEmitter = nullptr;
		ParticleTemplate *m_pTemplate = nullptr;

		Demo m_step = Demo::LINE;

		Line m_line;
		Bezier m_spline;
		Bezier m_spline2;
		Circle m_selectionCircle;

		int m_controlPoint = -1;

		void resetSplines();

	};
}