
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
		class ScaleUpdater : public IUpdater
		{

		public:

			/** @brief Creates a scale updater.
				@param endScale The scale that the particle should resize to as it expires. */
			ScaleUpdater(const Vector2 endScale = Vector2::ZERO) { m_endScale = endScale; }

			virtual ~ScaleUpdater() { }

			/** @brief Sets the end scale.
				@param endScale The scale that the particle should resize to as it expires. */
			virtual void SetEndScale(const Vector2 endScale) { m_endScale = endScale; }


			/** @brief Updates the scale of the specified particle.
				@param pParticle The particle to update.
				@param pGameTime The game's timing values. */
			virtual void Update(Particle *pParticle, const GameTime *pGameTime)
			{
				Vector2 startScale = pParticle->StartScale;
				float value = pParticle->InterpolationValue;
				pParticle->CurrentScale = Vector2::Lerp(startScale, m_endScale, value);
			}

		private:

			Vector2 m_endScale = Vector2::ZERO;

		};
	}
}