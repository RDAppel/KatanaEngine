
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
		bool Theme::Load(const std::string &path, ResourceManager *pManager)
		{
			std::ifstream fileIn(path.c_str(), std::ifstream::in);

			if (fileIn.is_open() && fileIn.good())
			{
				std::string line;
				std::vector<std::string> splitElements;

				int loadTexture = 1;
				int loadFont = 2;
				int loadColors = 3;
				int loadPanelSettings = 1;
				int loadToggleSettings = 4;
				int loadSliderSettings = 4;

				int fontSize = 10;
				Color colors[3];
				Region regions[3];

				while (getline(fileIn, line))
				{
					ParseComments(line);
					if (line.empty()) continue;

					if (loadTexture)
					{
						Texture *pTexture = pManager->Load<Texture>(line);
						SetTexture(pTexture);
						loadTexture--;
						continue;
					}
					
					if (loadFont)
					{
						if (loadFont == 2)
						{
							fontSize = atoi(line.c_str());
						}
						else if (loadFont == 1)
						{
							Font::SetLoadSize(fontSize, true);
							Font *pFont = pManager->Load<Font>(line);
							SetFont(pFont);
						}
						loadFont--;
						continue;
					}
					
					if (loadColors)
					{
						Split(line, ',', splitElements);
						float n[4] = { };
						for (uint8_t i = 0; i < 4; i++)
							n[i] = atof(splitElements[i].c_str());
						colors[3 - loadColors].R = n[0];
						colors[3 - loadColors].G = n[1];
						colors[3 - loadColors].B = n[2];
						colors[3 - loadColors].A = n[3];
						loadColors--;
						continue;
					}
					
					if (loadPanelSettings)
					{
						Split(line, ',', splitElements);
						int n[6] = { };
						for (uint8_t i = 0; i < 6; i++)
							n[i] = atoi(splitElements[i].c_str());
						SetupPanel(Point(n[0], n[1]), n[2], n[3], n[4], n[5]);
						loadPanelSettings--;
						continue;
					}
					
					if (loadToggleSettings)
					{
						if (loadToggleSettings > 1)
						{
							Region temp;
							if (Region::TryParse(line, temp))
							{
								regions[4 - loadToggleSettings] = temp;
							}
						}
						else if (loadToggleSettings == 1)
						{
							Split(line, ',', splitElements);
							int c0 = atoi(splitElements[0].c_str());
							int c1 = atoi(splitElements[1].c_str());
							
							SetupToggle(regions[0], regions[1],
							colors[c0], colors[c1], regions[2]);
						}

						loadToggleSettings--;
						continue;
					}
					
					if (loadSliderSettings)
					{
						if (loadSliderSettings > 1)
						{
							Region temp;
							if (Region::TryParse(line, temp))
							{
								regions[4 - loadSliderSettings] = temp;
							}
						}
						else if (loadSliderSettings == 1)
						{
							Split(line, ',', splitElements);
							int c0 = atoi(splitElements[0].c_str());
							int c1 = atoi(splitElements[1].c_str());

							SetupSlider(regions[0], regions[1],
								colors[c0], colors[c1], regions[2]);
						}

						loadSliderSettings--;
						continue;
					}
				}


				fileIn.close();
			}
			else
			{
				return false;
			}

			return true;
		}

		void Theme::SetupPanel(const Point &position, const int borderWidth)
		{
			SetupPanel(position, borderWidth, borderWidth);
		}

		void Theme::SetupPanel(const Point &position, const int borderWidth, const int borderHeight)
		{
			SetupPanel(position, borderHeight, borderWidth, borderWidth, borderHeight);
		}

		void Theme::SetupPanel(const Point &position, const int topBorderHeight, const int leftBorderWidth,
			const int rightBorderWidth, const int bottomBorderHeight)
		{
			const int leftInset = position.X + leftBorderWidth;
			const int topInset = position.Y + topBorderHeight;

			m_panelInfo.pTexture = m_pTexture;

			m_panelInfo.topBorderHeight = topBorderHeight;
			m_panelInfo.leftBorderWidth = leftBorderWidth;
			m_panelInfo.rightBorderWidth = rightBorderWidth;
			m_panelInfo.bottomBorderHeight = bottomBorderHeight;

			m_panelInfo.source[0].Set(position.X, position.Y, leftBorderWidth, topBorderHeight);
			m_panelInfo.source[1].Set(leftInset, position.Y, 1, topBorderHeight);
			m_panelInfo.source[2].Set(leftInset, position.Y, rightBorderWidth, topBorderHeight);

			m_panelInfo.source[3].Set(position.X, topInset, leftBorderWidth, 1);
			m_panelInfo.source[4].Set(leftInset, topInset, 1, 1);
			m_panelInfo.source[5].Set(leftInset, topInset, rightBorderWidth, 1);

			m_panelInfo.source[6].Set(position.X, topInset, leftBorderWidth, bottomBorderHeight);
			m_panelInfo.source[7].Set(leftInset, topInset, 1, bottomBorderHeight);
			m_panelInfo.source[8].Set(leftInset, topInset, rightBorderWidth, bottomBorderHeight);
		}

		void Theme::SetupToggle(const Region &backgroundSource, const Region &buttonSource,
			const Color &buttonColor, const Region &overlaySource)
		{
			SetupToggle(backgroundSource, buttonSource, buttonColor, buttonColor, overlaySource);
		}

		void Theme::SetupToggle(const Region &backgroundSource, const Region &buttonSource,
			const Color &buttonStartColor, const Color &buttonEndColor, const Region &overlaySource)
		{
			m_toggleInfo.pTexture = m_pTexture;

			m_toggleInfo.backgroundSource = backgroundSource;
			m_toggleInfo.buttonSource = buttonSource;
			m_toggleInfo.buttonStartColor = buttonStartColor;
			m_toggleInfo.buttonEndColor = buttonEndColor;
			m_toggleInfo.overlaySource = overlaySource;
		}

		void Theme::SetupSlider(const Region &backgroundSource, const Region &buttonSource,
			const Color &buttonColor, const Color &activeButtonColor, const Region &overlaySource)
		{
			int x = backgroundSource.X;
			int y = backgroundSource.Y;
			int width = backgroundSource.Width / 2;
			int height = backgroundSource.Height;

			m_sliderInfo.pTexture = m_pTexture;

			Region backgroundRegions[3] =
			{
				Region(x, y, width, height),
				Region(x + width, y, 1, height),
				Region(x + width, y, width, height)
			};

			for (int i = 0; i < 3; i++)
				m_sliderInfo.backgroundSource[i] = backgroundRegions[i];

			m_sliderInfo.buttonSource = buttonSource;
			m_sliderInfo.buttonColor = buttonColor;
			m_sliderInfo.activeButtonColor = activeButtonColor;
			m_sliderInfo.overlaySource = overlaySource;

		}

		Resource *Theme::Clone()
		{
			Theme *pClone = new Theme;

			pClone->m_pFont = m_pFont;
			pClone->m_pTexture = m_pTexture;
			pClone->m_panelInfo = m_panelInfo;
			pClone->m_sliderInfo = m_sliderInfo;
			pClone->m_toggleInfo = m_toggleInfo;

			return pClone;
		}

	}
}