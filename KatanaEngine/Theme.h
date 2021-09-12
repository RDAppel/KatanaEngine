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

#pragma once

namespace KatanaEngine
{
	namespace GUI
	{

		/** @brief Class for a GUI Theme. */
		class Theme : public Resource
		{

		public:

			Theme() { }
			Theme(Texture *pTexture) { m_pTexture = pTexture; }
			virtual ~Theme() { }

			/** @brief Used to determine if the theme is cloneable.
				@return Returns true if the theme is clonable, false otherwise. */
			virtual bool IsCloneable() const { return true; }

			/** @brief Used to create a clone of the theme.
				@return Returns a clone of the theme. */
			virtual Resource *Clone();

			virtual bool Load(const std::string &path, ResourceManager *pManager);

			virtual Texture *GetTexture() { return m_pTexture; }

			virtual void SetTexture(Texture *pTexture) { m_pTexture = pTexture; }

			virtual Font *GetFont(const int index = 0) { return m_fonts[index]; }

			virtual void AddFont(Font *pFont) { m_fonts.push_back(pFont); }

			virtual void SetupPanel(const Point &position, const int borderWidth = 16);

			virtual void SetupPanel(const Point &position, const int borderWidth, const int borderHeight);

			virtual void SetupPanel(const Point &position, const int topBorderHeight,
				const int leftBorderWidth, const int rightBorderWidth, const int bottomBorderHeight);

			virtual void SetupToggle(const Region &backgroundSource, const Region &buttonSource,
				const Color &buttonColor, const Region &overlaySource);

			virtual void SetupToggle(const Region &backgroundSource, const Region &buttonSource,
				const Color &buttonStartColor, const Color &buttonEndColor, const Region &overlaySource);

			virtual void SetupSlider(const Region &backgroundSource, const Region &buttonSource,
				const Color &buttonColor, const Color &activeButtonColor, const Region &overlaySource);

		private:

			Texture *m_pTexture = nullptr;
			std::vector<Font *> m_fonts;
		};
	}
}