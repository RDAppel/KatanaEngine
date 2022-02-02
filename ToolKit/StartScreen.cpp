
#include "ToolKit.h"

namespace KatanaEngine
{
	namespace TK
	{
		StartScreen *pCurrent;

		void OnButtonClick(void *sender, MouseButton button) {
			if (button == MouseButton::LEFT)
			{
				std::cout << "LEFT\n";
				//pCurrent->GetScreenManager()->AddScreen(new TestScreen);
				pCurrent->GetSlider()->SetValue(0);
			}
			else if (button == MouseButton::RIGHT)
			{
				std::cout << "RIGHT\n";
				pCurrent->GetSlider()->SetValue(0.25f);
			}
			else if (button == MouseButton::CENTER)
			{
				std::cout << "CENTER\n";
				pCurrent->GetSlider()->SetValue(0.5f);
			}
			else if (button == MouseButton::BACK)
			{
				std::cout << "BACK\n";
				pCurrent->GetSlider()->SetValue(1);
			}
			else if (button == MouseButton::FORWARD)
			{
				std::cout << "FORWARD\n";
			}
		}

		void OnMainPanelMove(void *pSender) { std::cout << "MOVING\n"; }

		void OnSliderValueChange(void *pSender)
		{
			GUI::Slider *pSlider = (GUI::Slider *)pSender;
			std::cout << pSlider->GetValue() << "\n";
		}

		StartScreen::StartScreen()
		{
			pCurrent = this;

			m_panel.SetPosition(10, 10);
			m_panel.SetSize(256, 512);
			m_panel.SetMoveCallback(OnMainPanelMove);
			
			GUI::PanelHeader *pHeader = new GUI::PanelHeader;
			pHeader->SetSize(250, 30);
			m_panel.AddComponent(pHeader);

			GUI::Button *pButton = new GUI::Button;
			pButton->SetSize(32, 32);
			pButton->SetPosition(10, 40);
			pButton->SetOnClickCallback(OnButtonClick);
			m_panel.AddComponent(pButton);

			m_slider.SetSize(Point(256 - 20, 32));
			m_slider.SetHandleWidth(16);
			m_slider.SetPosition(10, 82);
			m_slider.SetOnValueChangeCallback(OnSliderValueChange);
			m_panel.AddComponent(&m_slider);
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
			pSpriteBatch->Draw(m_pBackgroundGradient, Vector2::ZERO, m_backgroundColor);
			pSpriteBatch->End();

			m_panel.Draw(pSpriteBatch);
		}
	}
}
