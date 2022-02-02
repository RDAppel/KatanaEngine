
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
	namespace PE
	{

		ParticleTemplate *ParticleTemplate::CreateEmptyTemplate()
		{
			return new ParticleTemplate;
		}

		ParticleTemplate *ParticleTemplate::CreateDefaultTemplate()
		{
			ParticleTemplate *pBlank = new ParticleTemplate;
			pBlank->AddInitializer(new DefaultInitializer);
			pBlank->AddUpdater(new DefaultUpdater);
			return pBlank;
		}

		ParticleTemplate *ParticleTemplate::CreateSimpleTemplate()
		{
			ParticleTemplate *pSimple = CreateDefaultTemplate();
			pSimple->AddInitializer(new RandomVelocityInitializer);
			pSimple->AddUpdater(new VelocityUpdater);
			pSimple->AddRenderer(new DefaultRenderer);
			return pSimple;
		}

		ParticleTemplate::~ParticleTemplate()
		{
			ClearInitializers();
			ClearUpdaters();
			ClearRenderers();
		}

		void ParticleTemplate::Initialize(Particle *pParticle, Vector2 position)
		{
			m_iIt = m_initializers.begin();
			for (; m_iIt != m_initializers.end(); m_iIt++)
			{
				(*m_iIt)->Initialize(pParticle, position);
			}
		}

		void ParticleTemplate::Update(Particle *pParticle, const GameTime *pGameTime)
		{
			m_uIt = m_updaters.begin();
			for (; m_uIt != m_updaters.end(); m_uIt++)
			{
				(*m_uIt)->Update(pParticle, pGameTime);
			}
		}

		void ParticleTemplate::Draw(Particle *pParticle, SpriteBatch *pSpriteBatch)
		{
			m_rIt = m_renderers.begin();
			for (; m_rIt != m_renderers.end(); m_rIt++)
			{
				(*m_rIt)->Draw(pParticle, pSpriteBatch);
			}
		}

		void ParticleTemplate::ClearComponents(bool initializers, bool updaters, bool renderers)
		{
			if (initializers) ClearInitializers();
			if (updaters) ClearUpdaters();
			if (renderers) ClearRenderers();
		}

		void ParticleTemplate::ClearInitializers()
		{
			m_iIt = m_initializers.begin();
			for (; m_iIt != m_initializers.end(); m_iIt++) delete *m_iIt;
			m_initializers.clear();
		}

		void ParticleTemplate::ClearUpdaters()
		{
			m_uIt = m_updaters.begin();
			for (; m_uIt != m_updaters.end(); m_uIt++) delete *m_uIt;
			m_updaters.clear();
		}

		void ParticleTemplate::ClearRenderers()
		{
			m_rIt = m_renderers.begin();
			for (; m_rIt != m_renderers.end(); m_rIt++) delete *m_rIt;
			m_renderers.clear();
		}
	}
}

