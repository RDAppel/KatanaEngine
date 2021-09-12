
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
		/** @brief Initializes particle velocities to random values. */
		class RandomVelocityInitializer : public IInitializer
		{

		public:

			/** @brief Creates a random velocity initializer.
				@param max The maximum length of the velocity to add to the particle.
				@param max The minimum length of the velocity to add to the particle. */
			RandomVelocityInitializer(const float max = 100, const float min = 0)
			{
				m_minLength = min; m_maxLength = max;
			}

			virtual ~RandomVelocityInitializer() { }

			/** @brief Sets the minimum length of the velocity.
				@param max The minimum length of the velocity to add to the particle. */
			virtual void SetMinLength(const float min) { m_minLength = min; }

			/** @brief Sets the maximum length of the velocity.
				@param max The maximum length of the velocity to add to the particle. */
			virtual void SetMaxLength(const float max) { m_maxLength = max; }

			/** @brief Initializes the velocity of the specified particle to a random vector.
				@param pParticle The particle to initialize.
				@param position The position of the emitter when the particle was activated. */
			virtual void Initialize(Particle *pParticle, Vector2 position)
			{
				float range = m_maxLength - m_minLength;
				float length = Math::GetRandomFloat() * range + m_minLength;
				pParticle->Velocity += Vector2::GetRandom(true) * length;
			}

		private:

			float m_minLength = 0;
			float m_maxLength = 100;

		};
	}
}