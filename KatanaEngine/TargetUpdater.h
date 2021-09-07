
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
		class TargetUpdater : public IUpdater
		{

		public:

			TargetUpdater(Vector2 target = Vector2::ZERO) { m_target = target; }

			virtual ~TargetUpdater() { }

			virtual void SetTarget(Vector2 target) { m_target = target; }

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