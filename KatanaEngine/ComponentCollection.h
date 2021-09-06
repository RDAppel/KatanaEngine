
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
		class ComponentCollection
		{

		public:

			ComponentCollection(Game *pGame) { m_pGame = pGame; }
			virtual ~ComponentCollection();

			virtual Game *GetGame() { return m_pGame; };

			virtual Theme *GetTheme() { return m_pTheme; }

			virtual void SetTheme(Theme *pTheme) { m_pTheme = pTheme; }

			virtual void AddComponent(Component *pComponent);

			virtual void HandleInput(const InputState *pInput);

			virtual void Update(const GameTime *pGameTime);

			virtual void Draw(SpriteBatch *pSpriteBatch);

		private:

			Game *m_pGame = nullptr;
			Theme *m_pTheme = nullptr;

			std::vector<Component *> m_components;
			std::vector<Component *>::iterator m_it;

		};
	}
}

