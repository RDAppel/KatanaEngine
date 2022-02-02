
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

		/** @brief Initializes particle velocities. */
		class VelocityInitializer : public IInitializer
		{

		public:

			/** @brief Creates a velocity initializer.
				@param velocity The velocity to add to the particle. */
			VelocityInitializer(const Vector2 velocity = 100 * Vector2::UNIT_Y) { m_velocity = velocity; }

			virtual ~VelocityInitializer() { }

			/** @brief Sets the velocity.
				@param velocity The velocity to add to the particle. */
			virtual void SetVelocity(const Vector2 velocity) { m_velocity = velocity; }

			/** @brief Initializes the velocity of the specified particle.
				@param pParticle The particle to initialize.
				@param position The position of the emitter when the particle was activated. */
			virtual void Initialize(Particle *pParticle, Vector2 position)
			{
				pParticle->Velocity += m_velocity;
			}

		private:

			Vector2 m_velocity = Vector2::UNIT_Y * 200;

		};
	}
}