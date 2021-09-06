
/* ---------------------------------------------------------------  /

	 ██╗  ██╗  █████╗  ████████╗  █████╗  ███╗   ██╗  █████╗
	 ██║ ██╔╝ ██╔══██╗ ╚══██╔══╝ ██╔══██╗ ████╗  ██║ ██╔══██╗
	 █████╔╝  ███████║    ██║    ███████║ ██╔██╗ ██║ ███████║
	 ██╔═██╗  ██╔══██║    ██║    ██╔══██║ ██║╚██╗██║ ██╔══██║
	 ██║  ██╗ ██║  ██║    ██║    ██║  ██║ ██║ ╚████║ ██║  ██║
	 ╚═╝  ╚═╝ ╚═╝  ╚═╝/\  ╚═╝    ╚═╝  ╚═╝ ╚═╝  ╚═══╝ ╚═╝  ╚═╝
   /vvvvvvvvvvvvvvvvvvv \=========================================,
   `^^^^^^^^^^^^^^^^^^^ /---------------------------------------"
		Katana Engine \/ © 2012 - Shuriken Studios LLC

/  --------------------------------------------------------------- */

#include "KatanaEngine.h"

namespace KatanaEngine
{
	namespace GUI
	{
		void Slider::SetValue(const float value)
		{
			m_value = value;

			int buttonWidth = GetTheme()->GetSliderInfo()->buttonSource.Width;
			int scrollableWidth = GetSize().X - buttonWidth;
			m_buttonPosition.X = Math::Lerp(0, scrollableWidth, value);
		}

		void Slider::HandleInput(const InputState *pInput)
		{
			Component::HandleInput(pInput);
			ThemeInfo *pInfo = GetTheme()->GetSliderInfo();
			Vector2 mouse = pInput->GetMousePosition();
			Vector2 position = GetPosition();
			
			int buttonWidth = pInfo->buttonSource.Width;
			int scrollableWidth = GetSize().X - buttonWidth;
			float buttonX = position.X + m_buttonPosition.X;

			if (IsMouseOver())
			{
				m_isMouseOverButton = buttonX <= mouse.X
					&& mouse.X <= buttonX + buttonWidth;

				if (m_isMouseOverButton)
				{
					if (pInput->IsNewMouseButtonPress(MouseButton::LEFT))
					{
						m_isDragging = true;
						m_dragOffset = mouse.X - buttonX;
					}

					pInput->SetMouseCursor(MouseCursor::LINK);
				}
			}
			else m_isMouseOverButton = false;

			if (m_isDragging)
			{
				m_buttonPosition.X = mouse.X - (m_dragOffset + position.X);
				if (m_buttonPosition.X < 0) m_buttonPosition.X = 0;
				else if (m_buttonPosition.X > scrollableWidth)
					m_buttonPosition.X = scrollableWidth;

				m_value = m_buttonPosition.X / scrollableWidth;
			}

			if (pInput->IsNewMouseButtonRelease(MouseButton::LEFT))
			{
				m_isDragging = false;
			}
		}

		void Slider::Draw(SpriteBatch *pSpriteBatch)
		{
			ThemeInfo *pInfo = GetTheme()->GetSliderInfo();
			Texture *pTexture = pInfo->pTexture;

			Vector2 position = GetPosition();

			Color color = (m_isMouseOverButton || m_isDragging)
				? pInfo->activeButtonColor : pInfo->buttonColor;

			int endWidths = pInfo->backgroundSource[1].Height;
			int middleWidth = GetSize().X - 2 * endWidths;
			Vector2 middleScale(middleWidth, 1);

			Vector2 positions[3] =
			{
				position + Vector2::UNIT_X * endWidths,
				position + Vector2::UNIT_X * (endWidths + middleWidth),
				position + m_buttonPosition
			};

			pSpriteBatch->Draw(pTexture, position, pInfo->backgroundSource[0]);
			pSpriteBatch->Draw(pTexture, positions[0], pInfo->backgroundSource[1], Color::WHITE, Vector2::ZERO, middleScale);
			pSpriteBatch->Draw(pTexture, positions[1], pInfo->backgroundSource[2]);

			pSpriteBatch->Draw(pTexture, positions[2], pInfo->buttonSource, color);
			pSpriteBatch->Draw(pTexture, positions[2], pInfo->overlaySource);
		}
	}
}