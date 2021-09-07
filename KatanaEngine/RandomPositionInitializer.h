
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
		class RandomPositionInitializer : public IInitializer
		{

		public:

			RandomPositionInitializer(const float max = 500, const float min = 0)
			{
				m_minDistance = min; m_maxDistance = max;
			}

			virtual ~RandomPositionInitializer() { }

			virtual void SetMinDistance(const float min) { m_minDistance = min; }

			virtual void SetMaxDistance(const float max) { m_maxDistance = max; }

			virtual void Initialize(Particle *pParticle, Vector2 position)
			{
				const float range = m_maxDistance - m_minDistance;
				const float distance = Math::GetRandomFloat() * range + m_minDistance;
				Vector2 offset = Vector2::GetRandom(true) * distance;
				pParticle->StartPosition = position + offset;
				pParticle->CurrentPosition = position + offset;
			}

		private:

			float m_minDistance = 0;
			float m_maxDistance = 500;

		};
	}
}
