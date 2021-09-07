
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
		class ColorUpdater : public IUpdater
		{

		public:

			ColorUpdater(const Color endColor = Color::BLACK) { m_endColor = endColor; }
			virtual ~ColorUpdater() { }

			virtual void SetEndColor(const Color endColor) { m_endColor = endColor; }

			virtual void Update(Particle *pParticle, const GameTime *pGameTime)
			{
				Color startColor = pParticle->StartColor;
				float value = pParticle->InterpolationValue;
				pParticle->CurrentColor = Color::Lerp(startColor, m_endColor, value);
			}

		private:

			Color m_endColor = Color::BLACK;

		};
	}
}
