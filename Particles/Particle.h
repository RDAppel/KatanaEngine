
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
		class ParticleTemplate;

		/** @brief Contains particle properties that can be modified to affect 
			it's rendering during it's lifespan. */
		struct Particle
		{
			Vector2 StartPosition = Vector2::ZERO;
			Vector2 CurrentPosition = Vector2::ZERO;
			Vector2 Velocity = Vector2::ZERO;
			Vector2 Acceleration = Vector2::ZERO;
			Vector2 StartScale = Vector2::ONE;
			Vector2 CurrentScale = Vector2::ONE;

			float StartRotation = 0;
			float CurrentRotation = 0;
			float AngularVelocity = 0;
			float AngularAcceleration = 0;
			float LifeSpan = 0;
			float Age = 0;
			float InterpolationValue = 0;
			float StartAlpha = 1;
			float CurrentAlpha = 1;

			Color StartColor = Color::WHITE;
			Color CurrentColor = Color::WHITE;

			ParticleTemplate *Template = nullptr;
		};
	}
}

