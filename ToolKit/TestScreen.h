
#pragma once

#include "ToolKit.h"

namespace KatanaEngine
{
	namespace TK
	{
		class TestScreen : public Screen
		{
		public:

			TestScreen();
			virtual ~TestScreen();

			virtual void LoadContent(ResourceManager *pResourceManager);

			virtual void HandleInput(const InputState *pInput);

			virtual void Update(const GameTime *pGameTime);

			virtual void Draw(SpriteBatch *pSpriteBatch);

			virtual void CallThis() { std::cout << "FROM TEST SCREEN\n"; }

		private:

			KatanaEngine::GUI::Button *m_pButton = nullptr;
		};
	}
}