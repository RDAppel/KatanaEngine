
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

		/** @brief Initializes particle scale values. */
		class ScaleInitializer : public IInitializer
		{

		public:

			/** @brief Creates a scale initializer.
				@param scale The scale to add to the particle. */
			ScaleInitializer(const Vector2 scale) { m_scale = scale; }

			virtual ~ScaleInitializer() { }

			/** @brief Sets the scale.
				@param scale The scale to multiply to the particle. */
			virtual void SetAlpha(const Vector2 scale) { m_scale = scale; }

			/** @brief Initializes the scale of the specified particle.
				@param pParticle The particle to initialize.
				@param position The position of the emitter when the particle was activated. */
			virtual void Initialize(Particle *pParticle, Vector2 position)
			{
				pParticle->StartScale *= m_scale;
				pParticle->CurrentScale *= m_scale;
			}

		private:

			Vector2 m_scale = Vector2::ONE;

		};
	}
}
