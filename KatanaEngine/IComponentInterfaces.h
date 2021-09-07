
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
		struct Particle;

		/** @brief Interface for initializing particles  */
		class IInitializer
		{

		public:

			virtual ~IInitializer() { }

			virtual void Initialize(Particle *pParticle, Vector2 position) = 0;

		};

		/** @brief Interface for updating particles  */
		class IUpdater
		{

		public:

			virtual ~IUpdater() { }

			virtual void Update(Particle *pParticle, const GameTime *pGameTime) = 0;

		};

		/** @brief Interface for rendering particles  */
		class IRenderer
		{

		public:

			virtual ~IRenderer() { }

			virtual void Draw(Particle *pParticle, SpriteBatch *pSpriteBatch) = 0;

		};
	}
}