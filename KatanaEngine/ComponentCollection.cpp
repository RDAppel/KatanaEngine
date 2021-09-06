
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

		ComponentCollection::~ComponentCollection()
		{
			m_it = m_components.begin();
			for (; m_it != m_components.end(); m_it++) delete *m_it;
		}

		void ComponentCollection::AddComponent(Component * pComponent)
		{
			m_components.push_back(pComponent);
			pComponent->SetTheme(m_pTheme);
		}

		void ComponentCollection::HandleInput(const InputState *pInput)
		{
			m_it = m_components.begin();
			for (; m_it != m_components.end(); m_it++)
			{
				Component *pComponent = *m_it;
				pComponent->HandleInput(pInput);
				if (pComponent->HasFocus()) break;
			}
		}

		void ComponentCollection::Update(const GameTime *pGameTime)
		{
			m_it = m_components.begin();
			for (; m_it != m_components.end(); m_it++)
			{
				(*m_it)->Update(pGameTime);
			}
		}

		void ComponentCollection::Draw(SpriteBatch *pSpriteBatch)
		{
			m_it = m_components.begin();
			for (; m_it != m_components.end(); m_it++)
			{
				(*m_it)->Draw(pSpriteBatch);
			}
		}
	}
}