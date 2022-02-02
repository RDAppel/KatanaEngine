
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

#pragma once

namespace KatanaEngine
{
	namespace Particles
	{

		/** @brief Initializes particle lifespans randomly. */
		class RandomLifespanInitializer : public IInitializer
		{

		public:

			/** @brief Creates a random lifespan initializer.
				@param max The maximum lifespan in seconds.
				@param min The minimum lifespan in seconds. */
			RandomLifespanInitializer(const float max = 1, const float min = 0)
			{
				m_min = min;
				m_max = max;
				m_range = m_max - m_min;
			}

			virtual ~RandomLifespanInitializer() { }

			/** @brief Sets the minimum lifespan.
				@param min The minimum lifespan in seconds. */
			virtual void SetMin(const float min) { m_min = min; m_range = m_max - m_min; }

			/** @brief Sets the maximum lifespan.
				@param max The maximum lifespan in seconds. */
			virtual void SetMax(const float max) { m_max = max; m_range = m_max - m_min; }

			/** @brief Initializes the lifespan of the specified particle.
				@param pParticle The particle to initialize.
				@param position The position of the emitter when the particle was activated. */
			virtual void Initialize(Particle *pParticle, Vector2 position)
			{
				pParticle->LifeSpan = Math::GetRandomFloat() * m_range + m_min;
			}

		private:

			float m_min = 0;
			float m_max = 0;
			float m_range = 0;

		};
	}
}