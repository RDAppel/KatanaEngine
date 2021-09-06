
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
		void Toggle::HandleInput(const InputState *pInput)
		{
			Component::HandleInput(pInput);

			if (IsMouseOver())
			{
				if (pInput->IsNewMouseButtonRelease(MouseButton::LEFT))
				{
					m_value = !m_value;
					m_transitionDirection = m_value ? 1 : -1;
				}

				GetGame()->ChangeMouseCursor(MouseCursor::LINK);
			}
		}

		void Toggle::Update(const GameTime *pGameTime)
		{
			Component::Update(pGameTime);
			ThemeInfo *pInfo = GetTheme()->GetToggleInfo();

			int offset = pInfo->backgroundSource.Width - pInfo->buttonSource.Width;
			Vector2 right(offset, 0);
			Vector2 left(0, 0);

			m_interpolationValue = m_value ? 1 : 0;

			if (m_transitionDirection && m_transitionTime)
			{
				m_transitionValue += pGameTime->GetTimeElapsed() * m_transitionDirection;

				if (m_transitionValue >= m_transitionTime)
				{
					m_transitionDirection = 0;
					m_transitionValue = m_transitionTime;
				}

				if (m_transitionValue < 0)
				{
					m_transitionDirection = 0;
					m_transitionValue = 0;
				}

				m_interpolationValue = m_transitionValue / m_transitionTime;
			}

			m_buttonPosition = Vector2::Lerp(left, right, m_interpolationValue, true);
		}

		void Toggle::Draw(SpriteBatch *pSpriteBatch)
		{
			ThemeInfo *pInfo = GetTheme()->GetToggleInfo();
			Texture *pTexture = pInfo->pTexture;

			Color start = pInfo->buttonStartColor;
			Color end = pInfo->buttonEndColor;

			Color color = (start == end) ? start :
				Color::Lerp(start, end, m_interpolationValue);

			Vector2 position = GetPosition();

			pSpriteBatch->Draw(pTexture, position, pInfo->backgroundSource);
			pSpriteBatch->Draw(pTexture, position + m_buttonPosition, pInfo->buttonSource, color);
			pSpriteBatch->Draw(pTexture, position + m_buttonPosition, pInfo->overlaySource);

		}
	}
}