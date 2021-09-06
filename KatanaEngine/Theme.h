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

			virtual Font *GetFont() { return m_pFont; }

			virtual void SetFont(Font *pFont) { m_pFont = pFont; }

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

			virtual Panel::ThemeInfo *GetPanelInfo() { return &m_panelInfo; }

			virtual Toggle::ThemeInfo *GetToggleInfo() { return &m_toggleInfo; }

			virtual Slider::ThemeInfo *GetSliderInfo() { return &m_sliderInfo; }

		private:

			Texture *m_pTexture = nullptr;
			Font *m_pFont = nullptr;

			Panel::ThemeInfo m_panelInfo;
			Toggle::ThemeInfo m_toggleInfo;
			Slider::ThemeInfo m_sliderInfo;
		};
	}
}