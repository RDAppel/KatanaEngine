
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

		class Component
		{

		public:

			Component(Game *pGame) { m_pGame = pGame; }

			virtual void LoadContent(ResourceManager *pResourceManager) { }

			virtual void HandleInput(const InputState *pInput);

			virtual void Update(const GameTime *pGameTime) { }

			virtual void Draw(SpriteBatch *pSpriteBatch) = 0;

			virtual bool IsMouseOver() const { return m_isMouseOver; }

			virtual void SetResizeCallback(OnResize callback) { m_onResize = callback; }

			virtual void SetMoveCallback(OnMove callback) { m_onMove = callback; }

			virtual Point GetSize() const { return m_size; }

			virtual void SetSize(const Point &size);

			virtual void SetSize(const int x, const int y) { SetSize(Point(x, y)); }

			virtual Point GetPosition() const { return m_position; }

			virtual void SetPosition(const Point &position);

			virtual void SetPosition(const int x, const int y) { SetPosition(Point(x, y)); }

			virtual Theme *GetTheme() { return m_pTheme; }

			virtual void SetTheme(Theme *pTheme) { m_pTheme = pTheme; }

			virtual bool HasFocus() const { return m_hasFocus; }

			virtual void Translate(const Point &translation);

		protected:

			virtual Game *GetGame() { return m_pGame; }

			virtual void SetHasFocus(bool hasFocus = true) { m_hasFocus = hasFocus; }


		private:

			void *m_onResize = nullptr;
			void *m_onMove = nullptr;

			bool m_isMouseOver = false;
			bool m_hasFocus = false;

			Point m_position;
			Point m_size;

			Theme *m_pTheme = nullptr;
			Game *m_pGame = nullptr;
		};
	}
}

