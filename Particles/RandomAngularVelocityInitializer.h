
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

		/** @brief Initializes particle angular velocities to a random value. */
		class RandomAngularVelocityInitializer : public IInitializer
		{

		public:

			/** @brief Creates a random angular velocity initializer.
				@param max The maximum angular velocity.
				@param min The minimum angular velocity. */
			RandomAngularVelocityInitializer(const float max = Math::PI, const float min = -Math::PI) {
				m_minAngle = min; m_maxAngle = max; updateRange();
			}

			virtual ~RandomAngularVelocityInitializer() { }

			/** @brief Sets the minimum angluar velocity.
				@param min The minimum angular velocity. */
			virtual void SetMinAngle(const float min) { m_minAngle = min; updateRange(); }

			/** @brief Sets the minimum angluar velocity.
				@param max The maximum angular velocity. */
			virtual void SetMaxAngle(const float max) { m_maxAngle = max; updateRange(); }

			/** @brief Initializes the angular velocity of the specified particle.
				@param pParticle The particle to initialize.
				@param position The position of the emitter when the particle was activated. */
			virtual void Initialize(Particle *pParticle, Vector2 position)
			{
				float angle = Math::GetRandomFloat() * m_range + m_minAngle;
				pParticle->AngularVelocity += angle;
			}

		private:

			float m_minAngle = -Math::PI;
			float m_maxAngle = Math::PI;

			float m_range = 2 * Math::PI;

			void updateRange() { m_range = m_maxAngle - m_minAngle; }

		};
	}
}
