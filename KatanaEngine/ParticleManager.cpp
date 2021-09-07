
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

		ParticleManager::~ParticleManager()
		{
			m_it = m_particles.begin();
			for (; m_it != m_particles.end(); m_it++) delete *m_it;
		}

		void ParticleManager::Update(const GameTime *pGameTime)
		{
			m_it = m_particles.begin();
			for (; m_it != m_particles.end(); m_it++)
			{
				Particle *pParticle = *m_it;

				// lifespan of zero is how we represent an inactive particle
				if (pParticle->LifeSpan > 0) // active particle
				{
					pParticle->Template->Update(pParticle, pGameTime);
				}
			}
		}


		void ParticleManager::Draw(SpriteBatch *pSpriteBatch)
		{
			pSpriteBatch->Begin(SpriteSortMode::TEXTURE, m_blendState);

			m_it = m_particles.begin();
			for (; m_it != m_particles.end(); ++m_it)
			{
				Particle *pParticle = *m_it;

				// lifespan of zero is how we represent an inactive particle
				if (pParticle->LifeSpan > 0) // active particle
				{
					pParticle->Template->Draw(pParticle, pSpriteBatch);
				}
			}

			pSpriteBatch->End();
		}

		bool ParticleManager::ActivateParticle(ParticleTemplate *pTemplate, const Vector2 position)
		{
			Particle *pParticle = nullptr;

			m_it = m_particles.begin();
			for (; m_it != m_particles.end(); ++m_it)
			{
				// lifespan of zero is how we represent an inactive particle
				if ((*m_it)->LifeSpan > 0) continue;  // active particle

				// found inactive particle
				pParticle = *m_it;
				break;
			}

			// no inactive particles in pool
			if (!pParticle) {
				if (!m_generatesNewParticles) return false;

				pParticle = new Particle;
				m_particles.push_back(pParticle);
			}

			pParticle->Template = pTemplate;
			pTemplate->Initialize(pParticle, position);

			return true;
		}

		void ParticleManager::GenerateParticles(const uint16_t count)
		{
			for (uint16_t i = 0; i < count; i++)
				m_particles.push_back(new Particle);
		}
	}
}