
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

		class Toggle : public Component
		{

		public:

			Toggle(Game *pGame) : Component(pGame) { }

			Toggle(ComponentCollection *pCollection)
				: Component(pCollection->GetGame())
			{
				pCollection->AddComponent(this);
			}

			virtual ~Toggle() { }

			virtual void HandleInput(const InputState *pInput);

			virtual void Update(const GameTime *pGameTime);

			virtual void Draw(SpriteBatch *pSpriteBatch);

			virtual void SetValueChangeCallback(OnResize callback) { m_onValueChange = callback; }

			virtual bool GetValue() const { return m_value; }

			virtual void SetValue(const bool value = true) { m_value = value; }

			virtual void SetEnabled(const bool enabled = true) { m_isEnabled = enabled; }

			virtual float GetTransitionTime() const { return m_transitionTime; }

			virtual void SetTransitionTime(const double seconds) { m_transitionTime = seconds;  }

			struct ThemeInfo
			{
				Texture *pTexture = nullptr;

				Region backgroundSource;
				Region buttonSource;
				Color buttonStartColor;
				Color buttonEndColor;
				Region overlaySource;
			};


		private:

			void *m_onValueChange = nullptr;

			bool m_value = false;
			bool m_isEnabled = true;

			double m_transitionTime = 0.25f;
			double m_transitionValue = 0;
			int8_t m_transitionDirection = 0;
			float m_interpolationValue = 0;

			Vector2 m_buttonPosition = Vector2::ZERO;
		};
	}
}

