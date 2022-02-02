
/* ---------------------------------------------------------------  /

	 ██╗  ██╗  █████╗  ████████╗  █████╗  ███╗   ██╗  █████╗
	 ██║ ██╔╝ ██╔══██╗ ╚══██╔══╝ ██╔══██╗ ████╗  ██║ ██╔══██╗
	 █████╔╝  ███████║    ██║    ███████║ ██╔██╗ ██║ ███████║
	 ██╔═██╗  ██╔══██║    ██║    ██╔══██║ ██║╚██╗██║ ██╔══██║
	 ██║  ██╗ ██║  ██║    ██║    ██║  ██║ ██║ ╚████║ ██║  ██║
	 ╚═╝  ╚═╝ ╚═╝  ╚═╝/\  ╚═╝    ╚═╝  ╚═╝ ╚═╝  ╚═══╝ ╚═╝  ╚═╝
   /vvvvvvvvvvvvvvvvvvv \====================== Game Engine ======,
   `^^^^^^^^^^^^^^^^^^^ /----------------- © 2012 - Ryan Appel -"
					  \/
/  --------------------------------------------------------------- */

#include "Particles.h"

namespace KatanaEngine
{
	namespace Particles
	{
		
		ParticleEmitter::ParticleEmitter(ParticleManager *pManager)
		{
			m_pManager = pManager;
		}
		
		void ParticleEmitter::Update(const GameTime *pGameTime)
		{
			// We need to figure out how many particles to release this frame.
			// Since we can't emit a fraction of a particle, we keep track of the fractional
			// particles and they'll get released on future updates.

			float newParticles = pGameTime->GetTimeElapsed()
				* m_particlesPerSecond * m_output;

			m_leftoverParticles += newParticles;

			int particlesToEmit = (int)m_leftoverParticles;
			m_leftoverParticles -= particlesToEmit;

			Emit(particlesToEmit);
		}

		void ParticleEmitter::Emit(const int count) { Emit(count, m_position); }

		void ParticleEmitter::Emit(const int count, const Vector2 &position)
		{
			for (int i = 0; i < count; i++)
			{
				m_pManager->ActivateParticle(m_pParticleTemplate, position);
			}
		}
	}
}