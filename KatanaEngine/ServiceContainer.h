#pragma once

namespace KatanaEngine
{
	class ServiceContainer
	{
		
	public:

		virtual bool AddService(IService *pService)
		{
			std::pair<std::string, IService *> pair(pService->GetID(), pService);
			return m_services.insert(pair).second;
		}

		virtual IService *GetService(const std::string &serviceId)
		{
			return m_services[serviceId];
		}

		virtual void Update(const GameTime *pGameTime, const InputState *pInput)
		{
			m_it = m_services.begin();
			for (; m_it != m_services.end(); m_it++)
			{
				m_it->second->HandleInput(pInput);
				m_it->second->Update(pGameTime);
			}
		}

		virtual void Draw(SpriteBatch *pSpriteBatch)
		{
			m_it = m_services.begin();
			for (; m_it != m_services.end(); m_it++)
			{
				m_it->second->Draw(pSpriteBatch);
			}
		}


	private:

		std::map<std::string, IService *> m_services;
		std::map<std::string, IService *>::iterator m_it;
	};
}