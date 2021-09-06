
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

		/** @brief Class for menu items contained in a MenuScreen. */
		class Panel : public Component
		{

		public:

			Panel() { }

			Panel(ComponentCollection *pCollection)
			{
				pCollection->AddComponent(this);
			}

			virtual ~Panel() { }

			virtual void Update(const GameTime *pGameTime);

			virtual void Draw(SpriteBatch *pSpriteBatch);

			virtual Point GetMinSize() const { return m_minSize; }

			virtual void AddChild(Component *pComponent);

			struct ThemeInfo
			{
				Texture *pTexture = nullptr;

				int topBorderHeight = 0;
				int leftBorderWidth = 0;
				int rightBorderWidth = 0;
				int bottomBorderHeight = 0;

				Region source[9] = { };
			};

		private:

			Vector2 m_texturePositions[9];
			Vector2 m_textureScales[9];

			Point m_minSize;
			Point m_previousSize;
			Point m_previousPosition;

			std::vector<Component *> m_children;
			std::vector<Component *>::iterator m_it;
		};
	}
}

