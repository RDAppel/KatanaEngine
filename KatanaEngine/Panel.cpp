
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

		void Panel::Update(const GameTime *pGameTime)
		{
			Point size = GetSize();
			Point position = GetPosition();

			if (size != m_previousSize)
			{
				ThemeInfo *pInfo = GetTheme()->GetPanelInfo();

				Point borderSizes(
					pInfo->leftBorderWidth + pInfo->rightBorderWidth,
					pInfo->topBorderHeight + pInfo->bottomBorderHeight
				);

				m_minSize.Set(
					Math::Max(m_minSize.X, borderSizes.X),
					Math::Max(m_minSize.Y, borderSizes.Y)
				);

				const int TOP = position.Y;
				const int LEFT = position.X;
				const int RIGHT = LEFT + size.X;
				const int BOTTOM = TOP + size.Y;

				int xs[3] = { LEFT, LEFT + pInfo->leftBorderWidth, RIGHT - pInfo->rightBorderWidth };
				int ys[3] = { TOP, TOP + pInfo->topBorderHeight, BOTTOM - pInfo->bottomBorderHeight };

				for (int i = 0; i < 9; i++)
				{
					int x = i % 3;
					int y = i / 3;

					m_texturePositions[i].Set(xs[x], ys[y]);
					m_textureScales[i].Set(1, 1);

					if (x == 1) m_textureScales[i].X = size.X - borderSizes.X;
					if (y == 1) m_textureScales[i].Y = size.Y - borderSizes.Y;
				}

				if (size.X < m_minSize.X) size.X = m_minSize.X;
				if (size.Y < m_minSize.Y) size.Y = m_minSize.Y;
			}

			if (position != m_previousPosition)
			{
				Point translation = position - m_previousPosition;
				m_it = m_children.begin();
				for (; m_it != m_children.end(); m_it++)
				{
					(*m_it)->Translate(translation);
				}
			}

			m_previousSize = size;
			m_previousPosition = position;
		}

		void Panel::Draw(SpriteBatch *pSpriteBatch)
		{
			Color color = Color::WHITE;

			ThemeInfo *pInfo = GetTheme()->GetPanelInfo();
			Texture *pTexture = pInfo->pTexture;

			for (int i = 0; i < 9; i++)
			{
				pSpriteBatch->Draw(pTexture, m_texturePositions[i], pInfo->source[i], color, Vector2::ZERO, m_textureScales[i]);
			}
		}

		void Panel::AddChild(Component *pComponent)
		{
			m_children.push_back(pComponent);
		}
	}
}