
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

		/** @brief Updates particle rotations. */
		class RotationUpdater : public IUpdater
		{

		public:

			/** @brief Creates a rotation updater. */
			RotationUpdater() { }

			virtual ~RotationUpdater() { }

			/** @brief Updates the rotation of the specified particle.
				@param pParticle The particle to update.
				@param pGameTime The game's timing values. */
			virtual void Update(Particle *pParticle, const GameTime *pGameTime)
			{
				pParticle->CurrentRotation += pParticle->AngularVelocity * pGameTime->GetTimeElapsed();
			}

		};
	}
}