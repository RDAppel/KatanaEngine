
/* ---------------------------------------------------------------  /

	 ██╗  ██╗  █████╗  ████████╗  █████╗  ███╗   ██╗  █████╗
	 ██║ ██╔╝ ██╔══██╗ ╚══██╔══╝ ██╔══██╗ ████╗  ██║ ██╔══██╗
	 █████╔╝  ███████║    ██║    ███████║ ██╔██╗ ██║ ███████║
	 ██╔═██╗  ██╔══██║    ██║    ██╔══██║ ██║╚██╗██║ ██╔══██║
	 ██║  ██╗ ██║  ██║    ██║    ██║  ██║ ██║ ╚████║ ██║  ██║
	 ╚═╝  ╚═╝ ╚═╝  ╚═╝/\  ╚═╝    ╚═╝  ╚═╝ ╚═╝  ╚═══╝ ╚═╝  ╚═╝
   /vvvvvvvvvvvvvvvvvvv \=========================================,
   `^^^^^^^^^^^^^^^^^^^ /---------------------------------------"
		Katana Engine \/ © 2012 - Shuriken Studios LLC

/  --------------------------------------------------------------- */

#pragma once

namespace KatanaEngine
{
	namespace PE
	{
		/** @brief Manages the active particles in a particle system. */
		class ParticleManager : public IService
		{

		public:

			/** @brief Instantiate a particle manager object.
				@param pGame A pointer to the game instance. */
			ParticleManager() { }
			virtual ~ParticleManager();

			virtual std::string GetID() const { return "ParticleManager"; }

			/** @brief Called when the game has determined that screen logic needs to be processed.
				@param pGameTime Timing values including time since last update. */
			virtual void Update(const GameTime *pGameTime);

			/** @brief Called when the game determines it is time to draw a frame.
				@param pSpriteBatch The game's sprite batch, used for rendering. */
			virtual void Draw(SpriteBatch *pSpriteBatch);


			// todo: comments for following functions
			virtual bool ActivateParticle(ParticleTemplate *pTemplate, const Vector2 position);

			virtual bool GetGeneratesNewParticles() const { return m_generatesNewParticles; }

			virtual void SetGeneratesNewParticles(const bool generates = true) { m_generatesNewParticles = generates; }

			virtual void GenerateParticles(const uint16_t count);

			virtual void SetBlendState(const BlendState blendState) { m_blendState = blendState; }

		private:

			Game *m_pGame = nullptr;

			bool m_generatesNewParticles = true;

			std::vector<Particle *> m_particles;
			std::vector<Particle *>::iterator m_it;

			BlendState m_blendState = BlendState::ADDITIVE;
		};
	}
}

