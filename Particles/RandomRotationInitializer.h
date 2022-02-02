
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

		/** @brief Initializes particle rotations randomly. */
		class RandomRotationInitializer : public IInitializer
		{

		public:

			/** @brief Creates a random rotation initializer.
				@param max The maximum rotation of the particle.
				@param min The minimum rotation of the particle. */
			RandomRotationInitializer(const float max = 2 * Math::PI, const float min = 0)
			{
				m_maxAngle = max;
			}

			virtual ~RandomRotationInitializer() { }

			/** @brief Sets the minimum angle.
				@param min The minimum rotation of the particle. */
			virtual void SetMinAngle(const float min) { m_minAngle = min; }

			/** @brief Sets the maximum angle.
				@param max The maximum rotation of the particle. */
			virtual void SetMaxAngle(const float max) { m_maxAngle = max; }

			/** @brief Initializes the rotation of the specified particle.
				@param pParticle The particle to initialize.
				@param position The position of the emitter when the particle was activated. */
			virtual void Initialize(Particle *pParticle, Vector2 position)
			{
				const float range = m_maxAngle - m_minAngle;
				const float rotation = Math::GetRandomFloat() * range + m_minAngle;
				pParticle->StartRotation += rotation;
				pParticle->CurrentRotation += rotation;
			}

		private:

			float m_minAngle = 0;
			float m_maxAngle = 2 * Math::PI;

		};
	}
}
