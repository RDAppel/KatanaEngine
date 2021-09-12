
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
		class PanelHeader : public ComponentHandle
		{

		public:

			PanelHeader(const bool isDraggable = true) { m_isDraggable = isDraggable; }

			virtual ~PanelHeader() { }

			virtual void HandleInput(const InputState *pInput)
			{
				if (m_isDraggable) ComponentHandle::HandleInput(pInput);
			}

			virtual void Update(const GameTime *pGameTime)
			{
				ComponentHandle::Update(pGameTime);

				Point size = GetSize();
				size.X = GetContainer()->GetSize().X;
				SetSize(size);
				m_rectangle.Set(size, GetPosition());
			}

			virtual void Draw(SpriteBatch *pSpriteBatch)
			{
				Color color = m_color;

				if (m_isDraggable)
				{
					if (IsMouseOver() || IsBeingDragged()) color = m_highlightColor;
				}
		
				m_rectangle.DrawPrimitive(color);
			}

			virtual void SetIsDraggable(const bool isDraggable = true) { m_isDraggable = isDraggable; }

			virtual bool IsDraggable() const { return m_isDraggable; }

		private:

			Rectangle m_rectangle;

			bool m_isDraggable = true;

			Color m_color = Color(0.92578125f, 0.5625f, 0.06640625f);
			Color m_highlightColor = Color(0.796875f, 0.32421875f, 0.17578125f);

		};
	}
}
