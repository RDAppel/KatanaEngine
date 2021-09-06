
/*	 ██╗  ██╗  █████╗  ████████╗  █████╗  ███╗   ██╗  █████╗ 
	 ██║ ██╔╝ ██╔══██╗ ╚══██╔══╝ ██╔══██╗ ████╗  ██║ ██╔══██╗
	 █████╔╝  ███████║    ██║    ███████║ ██╔██╗ ██║ ███████║
	 ██╔═██╗  ██╔══██║    ██║    ██╔══██║ ██║╚██╗██║ ██╔══██║
	 ██║  ██╗ ██║  ██║    ██║    ██║  ██║ ██║ ╚████║ ██║  ██║
	 ╚═╝  ╚═╝ ╚═╝  ╚═╝/\  ╚═╝    ╚═╝  ╚═╝ ╚═╝  ╚═══╝ ╚═╝  ╚═╝
   /vvvvvvvvvvvvvvvvvvv \=========================================,
   `^^^^^^^^^^^^^^^^^^^ /---------------------------------------"
        Katana Engine \/ © 2012 - Shuriken Studios LLC              */

#pragma once

namespace KatanaEngine
{

	/** @brief Defines the buttons for a mouse. */
	enum class MouseButton
	{
		LEFT	= 1 << 0,	/**< Represents the Left mouse button. */
		RIGHT	= 1 << 1,	/**< Represents the Right mouse button. */
		CENTER	= 1 << 2,	/**< Represents the Center mouse button. */
		BACK	= 1 << 3,	/**< Represents the Back mouse button. */
		FORWARD	= 1 << 4	/**< Represents the Foreward mouse button. */
	};

	enum class MouseCursor
	{
		NONE = 0,
		DEFAULT = 1,
		ARROW = 2,
		BUSY = 3,
		QUESTION = 4,
		EDIT = 5,
		MOVE = 6,
		RESIZE_N = 7,
		RESIZE_W = 8,
		RESIZE_S = 9,
		RESIZE_E = 10,
		RESIZE_NW = 11,
		RESIZE_SW = 12,
		RESIZE_SE = 13,
		RESIZE_NE = 14,
		PROGRESS = 15,
		PRECISION = 16,
		LINK = 17,
		ALT_SELECT = 18,
		UNAVAILABLE = 19,
		MAX
	};
}