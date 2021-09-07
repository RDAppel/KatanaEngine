
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
		class RandomVelocityInitializer : public IInitializer
		{

		public:

			RandomVelocityInitializer(const float max = 100, const float min = 0)
			{
				m_minLength = min; m_maxLength = max;
			}

			virtual ~RandomVelocityInitializer() { }

			virtual void SetMinLength(const float min) { m_minLength = min; }

			virtual void SetMaxLength(const float max) { m_maxLength = max; }

			virtual void Initialize(Particle *pParticle, Vector2 position)
			{
				float range = m_maxLength - m_minLength;
				float length = Math::GetRandomFloat() * range + m_minLength;
				pParticle->Velocity += Vector2::GetRandom(true) * length;
			}

		private:

			float m_minLength = 0;
			float m_maxLength = 100;

		};
	}
}