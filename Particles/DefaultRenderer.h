
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
		/** @brief Renders a particle as a circle primitive. */
		class DefaultRenderer : public IRenderer
		{

		public:

			virtual ~DefaultRenderer() { }

			/** @brief Sets the radius of the circle primitive.
				@param radius The radius of the circle. */
			virtual void SetRadius(const float radius = 10) { m_circle.Radius = radius; }

			/** @brief Draws a circle primitive for the given particle.
				@param pParticle The particle to render.
				@param pSpriteBatch Unused, but necessary to implement the IRenderer interface.
				@see IRenderer */
			virtual void Draw(Particle *pParticle, SpriteBatch *pSpriteBatch)
			{
				m_circle.Position = pParticle->CurrentPosition;
				m_circle.Radius = pParticle->CurrentScale.X * 10;
				Color color = pParticle->CurrentColor * pParticle->CurrentAlpha;
				m_circle.DrawPrimitive(color);
			}

		private:

			Circle m_circle;

		};
	}
}