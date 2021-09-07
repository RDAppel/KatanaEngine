
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
		class RandomAngularVelocityInitializer : public IInitializer
		{

		public:

			RandomAngularVelocityInitializer(const float max = 2 * Math::PI, const float min = -2 * Math::PI) {
				m_minAngle = min; m_maxAngle = max; updateRange();
			}

			virtual ~RandomAngularVelocityInitializer() { }

			virtual void SetMinAngle(const float min) { m_minAngle = min; updateRange(); }

			virtual void SetMaxAngle(const float max) { m_maxAngle = max; updateRange(); }

			virtual void Initialize(Particle *pParticle, Vector2 position)
			{
				float angle = Math::GetRandomFloat() * m_range + m_minAngle;
				pParticle->AngularVelocity += angle;
			}

		private:

			float m_minAngle = 0;
			float m_maxAngle = 2 * Math::PI;

			float m_range = 2 * Math::PI;

			void updateRange() { m_range = m_maxAngle - m_minAngle; }

		};
	}
}
