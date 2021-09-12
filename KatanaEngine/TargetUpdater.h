
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

		/** @brief Updates particle positions and velocities to move them to a specified target. */
		class TargetUpdater : public IUpdater
		{

		public:

			/** @brief Creates a target updater.
				@param target The position that particles will move to during their lifespan. */
			TargetUpdater(Vector2 target = Vector2::ZERO) { m_target = target; }

			virtual ~TargetUpdater() { }

			/** @brief Sets the target.
				@param target The position that particles will move to during their lifespan. */
			virtual void SetTarget(Vector2 target) { m_target = target; }

			/** @brief Updates the position and velocity of the specified particle.
				@param pParticle The particle to update.
				@param pGameTime The game's timing values. */
			virtual void Update(Particle *pParticle, const GameTime *pGameTime)
			{
				const float value = pParticle->InterpolationValue;
				pParticle->CurrentPosition = Vector2::Lerp(pParticle->StartPosition, m_target, value);
				pParticle->Velocity = pParticle->CurrentPosition - pParticle->StartPosition;
			}

		private:

			Vector2 m_target = Vector2::ZERO;

		};
	}
}