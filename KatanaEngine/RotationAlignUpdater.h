
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
		class RotationAlignUpdater : public IUpdater
		{

		public:

			RotationAlignUpdater() { }

			virtual ~RotationAlignUpdater() { }

			virtual void Update(Particle *pParticle, const GameTime *pGameTime)
			{
				Vector2 velocity = pParticle->Velocity;
				const float angle = (float)atan2(velocity.Y, velocity.X);
				pParticle->CurrentRotation = angle;
				pParticle->AngularVelocity = 0;
			}
		};
	}
}