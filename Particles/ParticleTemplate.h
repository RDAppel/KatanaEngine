
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
	namespace Particles
	{

		/** @brief A collection of initializers, updaters and renderers that are applied to a particle
			during it's lifespan. */
		class ParticleTemplate
		{
		public:

			/** @brief Creates a particle template with no initializer, updater, or renderer.
				@returns An empty particle template. */
			static ParticleTemplate *CreateEmptyTemplate();

			/** @brief Creates the default particle template, which contains a default initializer
				and updater.
				@returns A default particle template.
				@see DefaultInitializer
				@see DefaultUpdater */
			static ParticleTemplate *CreateDefaultTemplate();

			/** @brief Creates a simple working template, which contains a Default Initializer,
				Random Velocity Initializer, Default Updater, Velocity Updater, and a Default Renderer.
				@returns A simple particle template.
				@see DefaultInitializer
				@see RandomVelocityInitializer
				@see DefaultUpdater
				@see VelocityUpdater
				@see DefaultRenderer */
			static ParticleTemplate *CreateSimpleTemplate();

			virtual ~ParticleTemplate();

			/** @brief Adds an initializer to the vector of components.
				@param pInitializer The initializer to add. */
			virtual void AddInitializer(IInitializer *pInitializer) { m_initializers.push_back(pInitializer); }

			/** @brief Adds an updater to the vector of components.
				@param pUpdater The updater to add. */
			virtual void AddUpdater(IUpdater *pUpdater) { m_updaters.push_back(pUpdater); }

			/** @brief Adds a render to the vector of components.
				@param pRenderer The renderer to add. */
			virtual void AddRenderer(IRenderer *pRenderer) { m_renderers.push_back(pRenderer); }

			/** @brief Initializes the specified particle using the templates initializer components.
				@param pParticle The particle to be initialized.
				@param position The emitter position when the particle became active. */
			virtual void Initialize(Particle *pParticle, Vector2 position);

			/** @brief Updates the specified particle using the templates updater components.
				@param pParticle The particle to be updated.
				@param pGameTime A reference to the game's timing values. */
			virtual void Update(Particle *pParticle, const GameTime *pGameTime);

			/** @brief Draws the specified particle using the templates renderer components.
				@param pParticle The particle to be rendered.
				@param pSpriteBatch The sprite batch instance that will be used to render. */
			virtual void Draw(Particle *pParticle, SpriteBatch *pSpriteBatch);

			/** @brief Deletes and clears the specified components. */
			virtual void ClearComponents(bool initializers = true, bool updaters = true,
				bool renderers = true);

			/** @brief Deletes and clears the vector of initializers. */
			virtual void ClearInitializers();

			/** @brief Deletes and clears the vector of updaters. */
			virtual void ClearUpdaters();

			/** @brief Deletes and clears the vector of renderers. */
			virtual void ClearRenderers();

		private:

			ParticleTemplate() { }

			std::vector<IInitializer *> m_initializers;
			std::vector<IInitializer *>::iterator m_iIt;

			std::vector<IUpdater *> m_updaters;
			std::vector<IUpdater *>::iterator m_uIt;
		
			std::vector<IRenderer *> m_renderers;
			std::vector<IRenderer *>::iterator m_rIt;
		};
	}
}

