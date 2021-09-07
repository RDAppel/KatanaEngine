
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
		class AlphaUpdater : public IUpdater
		{

		public:

			AlphaUpdater(const float endAlpha = 0) { m_endAlpha = endAlpha; }
			virtual ~AlphaUpdater() { }

			virtual void SetEndAlpha(const float endAlpha) { m_endAlpha = endAlpha; }

			virtual void Update(Particle *pParticle, const GameTime *pGameTime)
			{
				float startAlpha = pParticle->StartAlpha;
				float value = pParticle->InterpolationValue;
				pParticle->CurrentAlpha = Math::Lerp(startAlpha, m_endAlpha, value);
			}

		private:

			float m_endAlpha = 0;

		};
	}
}