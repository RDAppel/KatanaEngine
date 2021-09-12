
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
		{ }

		void Theme::SetupToggle(const Region &backgroundSource, const Region &buttonSource,
			const Color &buttonColor, const Region &overlaySource)
		{
			SetupToggle(backgroundSource, buttonSource, buttonColor, buttonColor, overlaySource);
		}

		void Theme::SetupToggle(const Region &backgroundSource, const Region &buttonSource,
			const Color &buttonStartColor, const Color &buttonEndColor, const Region &overlaySource)
		{ }

		void Theme::SetupSlider(const Region &backgroundSource, const Region &buttonSource,
			const Color &buttonColor, const Color &activeButtonColor, const Region &overlaySource)
		{ }

		Resource *Theme::Clone()
		{
			Theme *pClone = new Theme;

			pClone->m_fonts = m_fonts;
			pClone->m_pTexture = m_pTexture;

			return pClone;
		}

	}
}