
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
		class ComponentHandle : public Component
		{

		public:

			ComponentHandle() { }

			virtual ~ComponentHandle() { }

			virtual void HandleInput(const InputState *pInput)
			{
				Component::HandleInput(pInput);

				Point mouse = pInput->GetMousePosition();

				if (IsMouseOver())
				{
					if (pInput->IsNewMouseButtonPress(MouseButton::LEFT))
					{
						m_isBeingDragged = true;
						m_dragOffset = mouse - GetPosition();
					}
				}

				if (m_isBeingDragged)
				{
					if (pInput->IsNewMouseButtonRelease(MouseButton::LEFT))
					{
						m_isBeingDragged = false;
					}
					else
					{
						GetContainer()->SetPosition(mouse - m_dragOffset);
					}
				}
			}

			virtual bool IsBeingDragged() const { return m_isBeingDragged; }

		private:

			bool m_isBeingDragged = false;
			Point m_dragOffset;

		};
	}
}