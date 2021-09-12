
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

		class Theme;

		class Slider : public Component
		{

		public:

			Slider() { }

			Slider(ComponentCollection *pCollection)
			{
				pCollection->Add(this);
			}

			virtual ~Slider() { }

			virtual void HandleInput(const InputState *pInput);

			virtual void Draw(SpriteBatch *pSpriteBatch);

			virtual void SetValueChangeCallback(OnResize callback) { m_onValueChange = callback; }

			virtual float GetValue() const { return m_value; }

			virtual void SetValue(const float value);

			virtual void SetEnabled(const bool enabled = true) { m_isEnabled = enabled; }

			struct ThemeInfo
			{
				Texture *pTexture = nullptr;

				Region backgroundSource[3];
				Region buttonSource;
				Color buttonColor;
				Color activeButtonColor;
				Region overlaySource;
			};

		private:

			void *m_onValueChange = nullptr;

			float m_value = 0;
			bool m_isEnabled = true;
			bool m_isMouseOverButton = false;
			bool m_isDragging = false;

			int m_dragOffset = 0;

			Vector2 m_buttonPosition = Vector2::ZERO;

		};
	}
}

