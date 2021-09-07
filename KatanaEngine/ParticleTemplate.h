
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
	namespace PE
	{
		class ParticleTemplate
		{
		public:

			// todo: separate functions into cpp

			static ParticleTemplate *CreateBlankTemplate()
			{
				ParticleTemplate *pBlank = new ParticleTemplate;
				pBlank->AddInitializer(new DefaultInitializer);
				pBlank->AddUpdater(new DefaultUpdater);
				return pBlank;
			}

			static ParticleTemplate *CreateSimpleTemplate()
			{
				ParticleTemplate *pSimple = CreateBlankTemplate();
				pSimple->AddInitializer(new RandomVelocityInitializer);
				pSimple->AddUpdater(new VelocityUpdater);
				pSimple->AddRenderer(new DefaultRenderer);
				return pSimple;
			}

			virtual ~ParticleTemplate()
			{
				ClearInitializers();
				ClearUpdaters();
				ClearRenderers();
			}

			virtual void AddInitializer(IInitializer *pInitializer) { m_initializers.push_back(pInitializer); }

			virtual void AddUpdater(IUpdater *pUpdater) { m_updaters.push_back(pUpdater); }

			virtual void AddRenderer(IRenderer *pRenderer) { m_renderers.push_back(pRenderer); }

			virtual void Initialize(Particle *pParticle, Vector2 position)
			{
				m_iIt = m_initializers.begin();
				for (; m_iIt != m_initializers.end(); m_iIt++)
				{
					(*m_iIt)->Initialize(pParticle, position);
				}
			}

			virtual void Update(Particle *pParticle, const GameTime *pGameTime)
			{
				m_uIt = m_updaters.begin();
				for (; m_uIt != m_updaters.end(); m_uIt++)
				{
					(*m_uIt)->Update(pParticle, pGameTime);
				}
			}

			virtual void Draw(Particle *pParticle, SpriteBatch *pSpriteBatch)
			{
				m_rIt = m_renderers.begin();
				for (; m_rIt != m_renderers.end(); m_rIt++)
				{
					(*m_rIt)->Draw(pParticle, pSpriteBatch);
				}
			}

			virtual void ClearComponents(bool initializers = true, bool updaters = true, bool renderers = true)
			{
				if (initializers) ClearInitializers();
				if (updaters) ClearUpdaters();
				if (renderers) ClearRenderers();
			}

			virtual void ClearInitializers()
			{
				m_iIt = m_initializers.begin();
				for (; m_iIt != m_initializers.end(); m_iIt++) delete *m_iIt;
				m_initializers.clear();
			}

			virtual void ClearUpdaters()
			{
				m_uIt = m_updaters.begin();
				for (; m_uIt != m_updaters.end(); m_uIt++) delete *m_uIt;
				m_updaters.clear();
			}

			virtual void ClearRenderers()
			{
				m_rIt = m_renderers.begin();
				for (; m_rIt != m_renderers.end(); m_rIt++) delete *m_rIt;
				m_renderers.clear();
			}

		private:

			ParticleTemplate() { }

			std::vector<IInitializer *> m_initializers;
			std::vector<IInitializer *>::iterator m_iIt;

			std::vector<IUpdater *> m_updaters;
			std::vector<IUpdater *>::iterator m_uIt;
		
			std::vector<IRenderer *> m_renderers;
			std::vector<IRenderer *>::iterator m_rIt;
		};
	}
}

