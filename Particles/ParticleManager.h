
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

			/** @brief Activates an inactive particle.
				@param pTemplate The template that the particle will use for initialization, updating
				and rendering.
				@param position The position of the emitter, which is used to position the particle.
				@returns Returns true if an inactive particle was found and activated, false if there
				are no inactive particles in the pool. */
			virtual bool ActivateParticle(ParticleTemplate *pTemplate, const Vector2 position);

			/** @brief Gets whether or not the particle manager will create new particle instances.
				@returns Returns true if the particle manager will create new particles, false otherwise. */
			virtual bool GetGeneratesNewParticles() const { return m_generatesNewParticles; }

			/** @brief Sets whether or not the particle manager will create new particle instances.
				@param generates True if the manager should create particles, false otherwise. */
			virtual void SetGeneratesNewParticles(const bool generates = true) { m_generatesNewParticles = generates; }

			/** @brief Creates and adds particles to the pool.
				@param count The number of particles to generate. */
			virtual void GenerateParticles(const uint16_t count);

			/** @brief Sets the BlendState to use when the particles are rendered.
				@param blendState The blend state to use.
				@see SpriteBatch */
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