
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

		/** @brief Updates particle colors. */
		class ColorUpdater : public IUpdater
		{

		public:

			/** @brief Creates a color updater.
				@param endColor The color that the particle should fade to as it expires. */
			ColorUpdater(const Color endColor = Color::BLACK) { m_endColor = endColor; }

			virtual ~ColorUpdater() { }

			/** @brief Sets the end color.
				@param endColor The color that the particle should fade to as it expires. */
			virtual void SetEndColor(const Color endColor) { m_endColor = endColor; }

			/** @brief Updates the color of the specified particle.
				@param pParticle The particle to update.
				@param pGameTime The game's timing values. */
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
