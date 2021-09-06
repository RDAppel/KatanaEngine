
#pragma once

#include "PCH.h"

using namespace KatanaEngine;

namespace Test
{

	class TestScreen : public Screen
	{

	public:

		TestScreen() { }
		virtual ~TestScreen();

		virtual void LoadContent(ResourceManager *pResourceManager);

		virtual void UnloadContent();

		virtual void HandleInput(const InputState *pInput);

		virtual void Update(const GameTime *pGameTime);

		virtual void Draw(SpriteBatch *pSpriteBatch);

	private:

		GUI::Theme *m_pTheme = nullptr;

		GUI::Panel *m_pPanel = nullptr;
		GUI::Toggle *m_pToggle = nullptr;
		GUI::Slider *m_pSlider = nullptr;

		GUI::ComponentCollection *m_pComponents = nullptr;

		Texture *m_pTexture = nullptr;

	};
}