
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

		/** @brief Updates particle alpha values. */
		class AlphaUpdater : public IUpdater
		{

		public:

			/** @brief Creates an alpha updater.
				@param endAlpha The alpha value that the particle should fade to as it expires. */
			AlphaUpdater(const float endAlpha = 0) { m_endAlpha = endAlpha; }

			virtual ~AlphaUpdater() { }

			/** @brief Sets the end alpha value.
				@param endAlpha The alpha value that the particle should fade to as it expires. */
			virtual void SetEndAlpha(const float endAlpha) { m_endAlpha = endAlpha; }

			/** @brief Updates the alpha value of the specified particle.
				@param pParticle The particle to update.
				@param pGameTime The game's timing values. */
			virtual void Update(Particle *pParticle, const GameTime *pGameTime)
			{
				float startAlpha = pParticle->StartAlpha;
				float value = pParticle->InterpolationValue;
				pParticle->CurrentAlpha = Math::Lerp(startAlpha, m_endAlpha, value);
			}

		private:

			float m_endAlpha = 0;

		};
	}
}