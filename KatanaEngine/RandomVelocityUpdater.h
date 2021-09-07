
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
		class RandomVelocityUpdater : public IUpdater
		{

		public:

			RandomVelocityUpdater(const float max, const float min = 0) {
				m_minLength = min; m_maxLength = max; updateRange();
			}

			virtual ~RandomVelocityUpdater() { }

			virtual void SetMinLength(const float min) { m_minLength = min; updateRange(); }

			virtual void SetMaxLength(const float max) { m_maxLength = max; updateRange(); }

			virtual void Update(Particle *pParticle, const GameTime *pGameTime)
			{
				float length = Math::GetRandomFloat() * m_range + m_minLength;
				Vector2 velocity = Vector2::GetRandom(true) * length * pGameTime->GetTimeElapsed();
				pParticle->CurrentPosition += velocity;
			}

		private:

			float m_minLength = 0;
			float m_maxLength = 100;

			float m_range = 100;

			void updateRange() { m_range = m_maxLength - m_minLength; }

		};
	}
}