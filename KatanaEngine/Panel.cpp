
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
		void Panel::Draw(SpriteBatch *pSpriteBatch)
		{
			Rectangle rectangle;
			Point size = GetSize();
			Point position = GetPosition();

			// draw the background
			rectangle.Set(size, position);
			rectangle.DrawPrimitive(Color(0.21875f, 0.21875f, 0.21875f));

			// draw any children
			ComponentContainer::Draw(pSpriteBatch);

			// draw the outline and highlight
			rectangle.DrawPrimitive(Color::BLACK * 0.8f, 1.0f);
			rectangle.Set(size - Point(2, 2), position + Point(1, 1));
			rectangle.DrawPrimitive(Color::WHITE * 0.2f, 1.0f);
		}
	}
}