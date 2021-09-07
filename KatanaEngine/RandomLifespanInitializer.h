
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
		class RandomLifespanInitializer : public IInitializer
		{

		public:

			RandomLifespanInitializer(const float max = 1, const float min = 0)
			{
				m_min = min;
				m_max = max;
				m_range = m_max - m_min;
			}

			virtual ~RandomLifespanInitializer() { }

			virtual void SetMin(const float min) { m_min = min; m_range = m_max - m_min; }

			virtual void SetMax(const float max) { m_max = max; m_range = m_max - m_min; }

			virtual void Initialize(Particle *pParticle, Vector2 position)
			{
				pParticle->LifeSpan = Math::GetRandomFloat() * m_range + m_min;
			}

		private:

			float m_min = 0;
			float m_max = 0;
			float m_range = 0;

		};
	}
}