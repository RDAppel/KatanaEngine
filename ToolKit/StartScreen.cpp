
#include "ToolKit.h"

namespace KatanaEngine
{
	namespace TK
	{

		StartScreen::StartScreen()
		{
			m_panel.SetPosition(10, 10);
			m_panel.SetSize(250, 400);
			
			GUI::PanelHeader *pHeader = new GUI::PanelHeader;
			pHeader->SetSize(250, 30);
			m_panel.AddComponent(pHeader);
		}

		void StartScreen::LoadContent(ResourceManager *pResourceManager)
		{
			std::string path = "Textures\\LinearGradientBackground.png";
			m_pBackgroundGradient = pResourceManager->Load<Texture>(path);
		}

		void StartScreen::HandleInput(const InputState *pInput)
		{
			m_panel.HandleInput(pInput);
		}

		void StartScreen::Update(const GameTime *pGameTime)
		{
			m_panel.Update(pGameTime);
		}

		void StartScreen::Draw(SpriteBatch *pSpriteBatch)
		{
			pSpriteBatch->Begin();
			//pSpriteBatch->Draw(m_pBackgroundGradient, Vector2::ZERO, m_backgroundColor);

			m_panel.Draw(pSpriteBatch);

			pSpriteBatch->End();
		}
	}
}
