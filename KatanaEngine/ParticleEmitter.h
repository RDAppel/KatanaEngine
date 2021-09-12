
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

		/** @brief Emits particles. */
		class ParticleEmitter
		{

		public:

			ParticleEmitter(ParticleManager *pManager);
			virtual ~ParticleEmitter() { }

			/** @brief Called when the game has determined that game logic needs
				to be processed.
				@param pGameTime Timing values including time since last update. */
			virtual void Update(const GameTime *pGameTime);

			/** @brief Gets the output percentage of the emitter.
				@returns The output percentage of the emitter. */
			virtual float GetOutput() const { return m_output; }

			/** @brief Sets the output percentage for the emitter.
				@param output The value for the output. Zero is off, and one is full output.
				@remark An output greater than one will work, and will produce an output beyond 100%.
				Doing this can be usefull for testing but is not recommended for actual gameplay. */
			virtual void SetOutput(const float output) { m_output = output; }

			/** @brief Gets the position of the emitter.
				@returns The position of the emitter. */
			virtual Vector2 GetPosition() const { return m_position; }

			/** @brief Sets the position of the emitter.
				@param position The new position.
				@remark By default, the position of particles emitted will be interpolated between the
				emitter's current and previous position. To cancel this effect, you can simply call
				SetPosition() twice with the same position value. */
			virtual void SetPosition(const Vector2 position) { m_position = position; }

			/** @brief Gets the number of particles that will be emitted per second, when the output
				is set to one.
				@returns The number of particles per second to emit. */
			virtual float GetParticlesPerSecond() const { return m_particlesPerSecond; }

			/** @brief Sets the number of particles that will be emitted per second, when the output
				is set to one.
				@param particlesPerSecond The number of particles per second to emit.
				@see SetOutput() */
			virtual void SetParticlesPerSecond(const float particles) { m_particlesPerSecond = particles; }

			/** @brief Gets the particle template that the emitter uses.
				@return The emitter's particle template. */
			virtual ParticleTemplate *GetParticleTemplate() const { return m_pParticleTemplate; }

			/** @brief Sets the particle template that the emitter uses.
				@param particleTemplate The emitter's particle template. */
			virtual void SetParticleTemplate(ParticleTemplate *pTemplate) { m_pParticleTemplate = pTemplate; }

			/** @brief Emits a number of particles.
				@param count The number of particles to emit. */
			virtual void Emit(const int count);

			/** @brief Emits a number of particles at the specified position.
				@param count The number of particles to emit.
				@param position The position to initialize the particles.

				@overload */
			virtual void Emit(const int count, const Vector2 &position);

		private:

			float m_output = 0;
			float m_leftoverParticles = 0;
			float m_particlesPerSecond = 30;

			ParticleManager *m_pManager = nullptr;
			ParticleTemplate *m_pParticleTemplate = nullptr;

			Vector2 m_position = Vector2::ZERO;

		};
	}
}

