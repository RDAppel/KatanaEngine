
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

		/** @brief Initializes particle values to default. */
		class DefaultInitializer : public IInitializer
		{

		public:

			/** @brief Creates a default initializer.
				@param lifeSpan The lifeSpan of the particle in seconds. */
			DefaultInitializer(const float lifeSpan = 1) { m_lifeSpan = lifeSpan; }

			virtual ~DefaultInitializer() { }

			/** @brief Sets the lifespan.
				@param lifeSpan The lifeSpan of the particle in seconds. */
			virtual void SetLifeSpan(const float lifeSpan) { m_lifeSpan = lifeSpan; }

			/** @brief Initializes the default values of the specified particle. These values include
				age, position, rotation, velocity, color, alpha, scale, etc...
				@param pParticle The particle to initialize.
				@param position The position of the emitter when the particle was activated. */
			virtual void Initialize(Particle *pParticle, Vector2 position)
			{
				pParticle->Age = 0;
				pParticle->InterpolationValue = 0;
				pParticle->LifeSpan = m_lifeSpan;

				pParticle->StartPosition = position;
				pParticle->CurrentPosition = position;

				pParticle->AngularVelocity = 0;
				pParticle->AngularAcceleration = 0;

				pParticle->CurrentAlpha = 1;
				pParticle->StartAlpha = 1;

				pParticle->CurrentColor = Color::WHITE;
				pParticle->StartColor = Color::WHITE;

				pParticle->CurrentScale = Vector2::ONE;
				pParticle->StartScale = Vector2::ONE;

				pParticle->Velocity = Vector2::ZERO;
				pParticle->Acceleration = Vector2::ZERO;

			}

		private:

			float m_lifeSpan = 1;

		};
	}
}