
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

		/** @brief Initializes particle alpha values. */
		class AlphaInitializer : public IInitializer
		{

		public:

			/** @brief Creates a alpha initializer.
				@param alpha The alpha to render the particle. */
			AlphaInitializer(const float alpha) { m_alpha = alpha; }

			virtual ~AlphaInitializer() { }

			/** @brief Sets the alpha.
				@param alpha The alpha value to render the particle. */
			virtual void SetAlpha(const float alpha) { m_alpha = alpha; }

			/** @brief Initializes the alpha of the specified particle.
				@param pParticle The particle to initialize.
				@param position The position of the emitter when the particle was activated. */
			virtual void Initialize(Particle *pParticle, Vector2 position)
			{
				pParticle->StartAlpha = m_alpha;
				pParticle->CurrentAlpha = m_alpha;
			}

		private:

			float m_alpha = 1;

		};
	}
}