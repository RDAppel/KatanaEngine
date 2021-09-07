
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
		class TextureRenderer : public IRenderer
		{

		public:

			TextureRenderer() { }

			TextureRenderer(Texture *pTexture) { m_pTexture = pTexture; }

			virtual ~TextureRenderer() { }

			virtual void SetTexture(Texture *pTexture) { m_pTexture = pTexture; }

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