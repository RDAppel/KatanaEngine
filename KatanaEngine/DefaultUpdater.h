
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
		class DefaultUpdater : public IUpdater
		{

		public:

			virtual ~DefaultUpdater() { }

			virtual void Update(Particle *pParticle, const GameTime *pGameTime)
			{
				if (pParticle->LifeSpan <= 0) return;

				pParticle->Age += (float)pGameTime->GetTimeElapsed();
				pParticle->InterpolationValue = pParticle->Age / pParticle->LifeSpan;

				// lifespan of zero is how we represent an inactive particle
				if (pParticle->Age > pParticle->LifeSpan) pParticle->LifeSpan = 0;
			}

		};
	}
}