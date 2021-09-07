
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
		class RandomRotationInitializer : public IInitializer
		{

		public:

			RandomRotationInitializer(const float max = 2 * Math::PI, const float min = 0)
			{
				m_minAngle = min; m_maxAngle = max;
			}

			virtual ~RandomRotationInitializer() { }

			virtual void SetMinAngle(const float min) { m_minAngle = min; }

			virtual void SetMaxAngle(const float max) { m_maxAngle = max; }

			virtual void Initialize(Particle *pParticle, Vector2 position)
			{
				const float range = m_maxAngle - m_minAngle;
				const float rotation = Math::GetRandomFloat() * range + m_minAngle;
				pParticle->StartRotation += rotation;
				pParticle->CurrentRotation += rotation;
			}

		private:

			float m_minAngle = 0;
			float m_maxAngle = 2 * Math::PI;

		};
	}
}
