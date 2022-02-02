
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
		/** @brief Renders the specified Texture for each particle. */
		class TextureRenderer : public IRenderer
		{

		public:

			/** @brief Instantiates a Texture Renderer object. */
			TextureRenderer() { }

			/** @brief Instantiates a Texture Renderer object, and sets the Texture. */
			TextureRenderer(Texture *pTexture) { m_pTexture = pTexture; }

			virtual ~TextureRenderer() { }

			/** @brief Sets the texture to be rendered.
				@param pTexture the texture to be rendered. */
			virtual void SetTexture(Texture *pTexture) { m_pTexture = pTexture; }

			/** @brief Draws the texture for the given particle.
				@param pParticle The particle to render.
				@param pSpriteBatch The sprite batch used to render the texture. */
			virtual void Draw(Particle *pParticle, SpriteBatch *pSpriteBatch)
			{
				if (!m_pTexture) return;

				Vector2 position = pParticle->CurrentPosition;
				Color color = pParticle->CurrentColor * pParticle->CurrentAlpha;
				Vector2 scale = pParticle->CurrentScale;
				float rotation = pParticle->CurrentRotation;

				pSpriteBatch->Draw(m_pTexture, position, color, m_pTexture->GetCenter(), scale, rotation);
			}

		private:

			Texture *m_pTexture = nullptr;

		};
	}
}