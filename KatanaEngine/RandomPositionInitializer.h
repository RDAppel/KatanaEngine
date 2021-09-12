
/*	 ██╗  ██╗  █████╗  ████████╗  █████╗  ███╗   ██╗  █████╗
	 ██║ ██╔╝ ██╔══██╗ ╚══██╔══╝ ██╔══██╗ ████╗  ██║ ██╔══██╗
	 █████╔╝  ███████║    ██║    ███████║ ██╔██╗ ██║ ███████║
	 ██╔═██╗  ██╔══██║    ██║    ██╔══██║ ██║╚██╗██║ ██╔══██║
	 ██║  ██╗ ██║  ██║    ██║    ██║  ██║ ██║ ╚████║ ██║  ██║
	 ╚═╝  ╚═╝ ╚═╝  ╚═╝/\  ╚═╝    ╚═╝  ╚═╝ ╚═╝  ╚═══╝ ╚═╝  ╚═╝
   /vvvvvvvvvvvvvvvvvvv \=========================================,
   `^^^^^^^^^^^^^^^^^^^ /---------------------------------------"
		Katana Engine \/ © 2012 - Shuriken Studios LLC              */

#pragma once

namespace KatanaEngine
{
	namespace PE
	{

		/** @brief Initializes particle positions randomly. */
		class RandomPositionInitializer : public IInitializer
		{

		public:

			/** @brief Creates a random position initializer.
				@param max The maximum distance from the emitter.
				@param min The minimum distance from the emitter. */
			RandomPositionInitializer(const float max = 500, const float min = 0)
			{
				m_minDistance = min; m_maxDistance = max;
			}

			virtual ~RandomPositionInitializer() { }

			/** @brief Sets the minimum distance.
				@param min The minimum distance from the emitter. */
			virtual void SetMinDistance(const float min) { m_minDistance = min; }

			/** @brief Sets the maximum distance.
				@param max The maximum distance from the emitter. */
			virtual void SetMaxDistance(const float max) { m_maxDistance = max; }

			/** @brief Initializes the position of the specified particle.
				@param pParticle The particle to initialize.
				@param position The position of the emitter when the particle was activated. */
			virtual void Initialize(Particle *pParticle, Vector2 position)
			{
				const float range = m_maxDistance - m_minDistance;
				const float distance = Math::GetRandomFloat() * range + m_minDistance;
				Vector2 offset = Vector2::GetRandom(true) * distance;
				pParticle->StartPosition = position + offset;
				pParticle->CurrentPosition = position + offset;
			}

		private:

			float m_minDistance = 0;
			float m_maxDistance = 500;

		};
	}
}
