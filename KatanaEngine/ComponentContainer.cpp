
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

		ComponentContainer::~ComponentContainer()
		{
			m_it = m_components.begin();
			for (; m_it != m_components.end(); m_it++) delete *m_it;
			m_components.clear();
		}


		void ComponentContainer::HandleInput(const InputState *pInput)
		{
			Component::HandleInput(pInput);

			m_isMouseOverChild = false;

			m_it = m_components.begin();
			for (; m_it != m_components.end(); m_it++)
			{
				Component *pComponent = *m_it;
				pComponent->HandleInput(pInput);

				if (pComponent->IsMouseOver()) m_isMouseOverChild = true;
			}
		}

		void ComponentContainer::Update(const GameTime *pGameTime)
		{
			Component::Update(pGameTime);

			Point position = GetPosition();
			Point offset(0, 0);
			if (m_previousPosition != position)
			{
				offset = position - m_previousPosition;
			}

			m_it = m_components.begin();
			for (; m_it != m_components.end(); m_it++)
			{
				Component *pComponent = *m_it;
				if (!offset.IsOrigin()) pComponent->Translate(offset);
				pComponent->Update(pGameTime);
			}

			m_previousPosition = position;
		}

		void ComponentContainer::Draw(SpriteBatch *pSpriteBatch)
		{
			Component::Draw(pSpriteBatch);

			m_it = m_components.begin();
			for (; m_it != m_components.end(); m_it++) (*m_it)->Draw(pSpriteBatch);
		}

		void ComponentContainer::AddComponent(Component *pComponent)
		{
			pComponent->SetContainer(this);
			m_components.push_back(pComponent);
		}
	}
}