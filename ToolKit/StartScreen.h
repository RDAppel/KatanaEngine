
#pragma once

#include "ToolKit.h"

namespace KatanaEngine
{
	namespace TK
	{
		class StartScreen : public Screen
		{
		public:

			StartScreen();
			virtual ~StartScreen() { }

			virtual void LoadContent(ResourceManager *pResourceManager);

			//virtual void UnloadContent() { }

			virtual void HandleInput(const InputState *pInput);

			virtual void Update(const GameTime *pGameTime);

			virtual void Draw(SpriteBatch *pSpriteBatch);


		private:

			GUI::Panel m_panel;

			Texture *m_pBackgroundGradient = nullptr;
			Color m_backgroundColor = Color(0.796875f, 0.32421875f, 0.17578125f);

		};
	}
}
