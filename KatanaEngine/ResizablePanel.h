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

		/** @brief Class for menu items contained in a MenuScreen. */
		class ResizablePanel : public Panel
		{

		public:

			ResizablePanel(Game *pGame);

			ResizablePanel(ComponentCollection *pCollection)
				: Panel(pCollection)
			{ }

			virtual ~ResizablePanel() { }


			/** @brief Called when the game has determined that player input needs to be processed.
				@param pInput The current state of all player input devices. */
			virtual void HandleInput(const InputState *pInput);

		private:

			int m_handleWidth = 8;
			uint8_t m_dragMask = 0;
			Point m_dragStart;

			bool m_specialCursor = false;
		};
	}
}

