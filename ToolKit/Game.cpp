
#include "ToolKit.h"

namespace KatanaEngine
{
	namespace TK
	{
		Game::Game()
		{
			SetScreenResolution(1600, 900);
			SetClearColor(Color(0.92578125f, 0.5625f, 0.06640625f));

			SetResourceDirectory("..\\ToolKit\\Content\\");

			m_pScreenManager = InitializeScreenManager();
			m_pScreenManager->AddScreen(new StartScreen);
		}
	}
}