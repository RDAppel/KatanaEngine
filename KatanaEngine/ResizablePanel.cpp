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
		void OnResizeCallback(Component *pComponent)
		{
			pComponent->GetSize().Display();
		}

		
		ResizablePanel::ResizablePanel()
		{
			SetResizeCallback(OnResizeCallback);
		}
		
			
		void ResizablePanel::HandleInput(const InputState *pInput)
		{
			Panel::HandleInput(pInput);

			Point mouse = pInput->GetMousePosition();

			const uint8_t TOP_MASK = 1 << 0;
			const uint8_t LEFT_MASK = 1 << 1;
			const uint8_t RIGHT_MASK = 1 << 2;
			const uint8_t BOTTOM_MASK = 1 << 3;


			Point position = GetPosition();
			Point size = GetSize();
			int top = position.Y;
			int left = position.X;
			int right = left + size.X;
			int bottom = top + size.Y;

			int hoverMask = 0;

			if (IsMouseOver() && !m_dragMask)
			{
				if (mouse.X < left + m_handleWidth) hoverMask |= LEFT_MASK;
				if (mouse.X > right - m_handleWidth) hoverMask |= RIGHT_MASK;
				if (mouse.Y < top + m_handleWidth) hoverMask |= TOP_MASK;
				if (mouse.Y > bottom - m_handleWidth) hoverMask |= BOTTOM_MASK;

				if (hoverMask && pInput->IsNewMouseButtonPress(MouseButton::LEFT))
				{
					m_dragStart = mouse;
					m_dragMask = hoverMask;
				}
			}

			if ((!hoverMask && m_specialCursor) && !m_dragMask)
			{
				pInput->SetMouseCursor(MouseCursor::DEFAULT);
				m_specialCursor = false;
			}
			else
			{
				if (hoverMask == TOP_MASK) pInput->SetMouseCursor(MouseCursor::RESIZE_N);
				if (hoverMask == LEFT_MASK) pInput->SetMouseCursor(MouseCursor::RESIZE_W);
				if (hoverMask == RIGHT_MASK) pInput->SetMouseCursor(MouseCursor::RESIZE_E);
				if (hoverMask == BOTTOM_MASK) pInput->SetMouseCursor(MouseCursor::RESIZE_S);

				if (hoverMask == (TOP_MASK | LEFT_MASK)) pInput->SetMouseCursor(MouseCursor::RESIZE_NW);
				if (hoverMask == (TOP_MASK | RIGHT_MASK)) pInput->SetMouseCursor(MouseCursor::RESIZE_NE);
				if (hoverMask == (BOTTOM_MASK | LEFT_MASK)) pInput->SetMouseCursor(MouseCursor::RESIZE_SW);
				if (hoverMask == (BOTTOM_MASK | RIGHT_MASK)) pInput->SetMouseCursor(MouseCursor::RESIZE_SE);

				m_specialCursor = true;
			}

			if (m_dragMask && pInput->IsMouseButtonUp(MouseButton::LEFT)) m_dragMask = 0;

			if (m_dragMask)
			{
				Point minSize = GetMinSize();

				if (m_dragMask & RIGHT_MASK)
				{
					size.X = Math::Max(mouse.X - left, minSize.X);
				}

				if (m_dragMask & LEFT_MASK)
				{
					size.X = Math::Max(right - mouse.X, minSize.X);
					left = right - size.X;
				}

				if (m_dragMask & BOTTOM_MASK)
				{
					size.Y = Math::Max(mouse.Y - top, minSize.Y);
				}

				if (m_dragMask & TOP_MASK)
				{
					size.Y = Math::Max(bottom - mouse.Y, minSize.Y);
					top = bottom - size.Y;
				}

				SetSize(size);
				SetPosition(left, top);
			}

			SetHasFocus(m_dragMask > 0);
		}
	}
}