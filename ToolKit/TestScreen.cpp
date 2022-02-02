
#include "ToolKit.h"

namespace KatanaEngine
{
	namespace TK
	{
		TestScreen *pCurrent;

		void NewOnClick(void *pSender, MouseButton button)
		{

			if (button == MouseButton::LEFT) pCurrent->CallThis();
			else if (button == MouseButton::RIGHT)
			{
				GUI::Button *pButton = (GUI::Button *)pSender;
				pButton->SetBaseColor(Color::BLUE);
			}
		}

		TestScreen::TestScreen()
		{
			pCurrent = this;

			SetTransitionInTime(1);
			SetTransitionOutTime(0);

			m_pButton = new GUI::Button;
			m_pButton->SetOnClickCallback(NewOnClick);
			m_pButton->SetSize(100, 100);

			Show();
		}

		TestScreen::~TestScreen()
		{
		}

		void TestScreen::LoadContent(ResourceManager *pResourceManager)
		{
		}

		void TestScreen::HandleInput(const InputState *pInput)
		{
			m_pButton->HandleInput(pInput);
		}

		void TestScreen::Update(const GameTime *pGameTime)
		{
			m_pButton->Update(pGameTime);
		}

		void TestScreen::Draw(SpriteBatch *pSpriteBatch)
		{
			m_pButton->Draw(pSpriteBatch);
		}
	}
}
