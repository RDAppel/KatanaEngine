
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
		void Component::HandleInput(const InputState *pInput)
		{
			Point mouse = pInput->GetMousePosition();

			Point position = GetPosition();
			Point size = GetSize();

			const int TOP = position.Y;
			const int LEFT = position.X;
			const int RIGHT = LEFT + size.X;
			const int BOTTOM = TOP + size.Y;

			m_isMouseOver =
				mouse.X >= LEFT && mouse.X <= RIGHT &&
				mouse.Y >= TOP && mouse.Y <= BOTTOM;
		}

		void Component::SetPosition(const Point &position)
		{
			m_position = position;
			if (m_onMove) ((OnMove)m_onMove)(this);
		}

		void Component::SetSize(const Point &size)
		{
			m_size = size;
			if (m_onResize) ((OnResize)m_onResize)(this);
		}

		void Component::Translate(const Point &translation)
		{
			SetPosition(m_position + translation);
		}

	}
}