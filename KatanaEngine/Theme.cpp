
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
			// todo: am I actually going to use this?
			/*
			std::ifstream fileIn(path.c_str(), std::ifstream::in);

			if (fileIn.is_open() && fileIn.good())
			{
				std::string line;

				enum class Step
				{
					LOAD_TEXTURE,
					LOAD_FONTS,
					LOAD_COLORS,

					SETUP_PANEL,
					SETUP_TOGGLE,
					SETUP_SLIDER,

					COMPLETE
				};

				int step = (int)Step::LOAD_TEXTURE;
				int numFontsToLoad = -1;
				int numColorsToLoad = -1;
				int subStep = 0;
				std::vector<Color> colors;

				while (getline(fileIn, line))
				{
					StripComments(line);
					TrimLine(line);
					if (line.empty()) continue;

					bool cache = line.find("-cache") != std::string::npos;
					bool usecontentpath = line.find("-usecontentpath") != std::string::npos;

					if (step == (int)Step::LOAD_TEXTURE)
					{
						std::vector<std::string> parts;
						if (!TryParse<std::string>(line, parts)) return false;

						Texture *pTexture = pManager->Load<Texture>(parts[0], cache, usecontentpath);
						if (!pTexture) return false;

						SetTexture(pTexture);
				
						step++;
						continue;
					}

					if (step == (int)Step::LOAD_FONTS)
					{
						if (numFontsToLoad == -1)
						{
							numFontsToLoad = atoi(line.c_str());
							continue;
						}

						std::vector<std::string> parts;
						if (!TryParse<std::string>(line, parts)) return false;
						if (parts.size() < 2) return false;
							
						int size = atoi(parts[0].c_str());
						Font::SetLoadSize(size, true);
						Font *pFont = pManager->Load<Font>(parts[1], cache, usecontentpath);

						if (!pFont) return false;
						m_fonts.push_back(pFont);
						numFontsToLoad--;
						if (numFontsToLoad > 0) continue;

						step++;
						continue;
					}

					if (step == (int)Step::LOAD_COLORS)
					{
						if (numColorsToLoad == -1)
						{
							numColorsToLoad = atoi(line.c_str());
							continue;
						}

						Color color;
						if (!TryParseColor(line, color)) return false;
						colors.push_back(color);
						numColorsToLoad--;
						if (numColorsToLoad > 0) continue;

						step++;
						continue;
					}

					if (step == (int)Step::SETUP_PANEL)
					{
						std::vector<int> elements;
						if (!TryParse<int>(line, elements)) return false;

						if (subStep == 0)
						{
							if (elements.size() != 2) return false;

						}
					}

					/*
					if (loadPanelSettings)
					{
						//Split(line, ',', splitElements);
						std::vector<int> n;
						if (!TryParse<int>(line, n)) return false;
						//int n[6] = { };
						/*
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
							if (TryParseRegion(line, temp))
							{
								regions[4 - loadToggleSettings] = temp;
							}
							else return false;
						}
						else if (loadToggleSettings == 1)
						{
							std::vector<int> n;
							if (!TryParse<int>(line, n)) return false;

							SetupToggle(regions[0], regions[1],
							colors[n[0]], colors[n[1]], regions[2]);
						}

						loadToggleSettings--;
						continue;
					}

					if (loadSliderSettings)
					{
						if (loadSliderSettings > 1)
						{
							Region temp;
							if (TryParseRegion(line, temp))
							{
								regions[4 - loadSliderSettings] = temp;
							}
						}
						else if (loadSliderSettings == 1)
						{
							std::vector<int> n;
							if (!TryParse<int>(line, n)) return false;

							SetupSlider(regions[0], regions[1],
								colors[n[0]], colors[n[1]], regions[2]);
						}

						loadSliderSettings--;
						continue;
					}
				}
				}

				fileIn.close();
			}
			else
			{
				return false;
			}

			/***/
			//return true;

			return false;
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

			pClone->m_fonts = m_fonts;
			pClone->m_pTexture = m_pTexture;
			pClone->m_panelInfo = m_panelInfo;
			pClone->m_sliderInfo = m_sliderInfo;
			pClone->m_toggleInfo = m_toggleInfo;

			return pClone;
		}

	}
}