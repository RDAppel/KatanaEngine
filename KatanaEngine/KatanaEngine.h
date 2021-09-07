
#pragma once

#pragma message("")
#pragma message("")
#pragma message("         ██╗  ██╗  █████╗  ████████╗  █████╗  ███╗   ██╗  █████╗ ")
#pragma message("         ██║ ██╔╝ ██╔══██╗ ╚══██╔══╝ ██╔══██╗ ████╗  ██║ ██╔══██╗")
#pragma message("         █████╔╝  ███████║    ██║    ███████║ ██╔██╗ ██║ ███████║")
#pragma message("         ██╔═██╗  ██╔══██║    ██║    ██╔══██║ ██║╚██╗██║ ██╔══██║")
#pragma message("         ██║  ██╗ ██║  ██║    ██║    ██║  ██║ ██║ ╚████║ ██║  ██║")
#pragma message("         ╚═╝  ╚═╝ ╚═╝  ╚═╝/\\  ╚═╝    ╚═╝  ╚═╝ ╚═╝  ╚═══╝ ╚═╝  ╚═╝")
#pragma message("       /vvvvvvvvvvvvvvvvvvv \\=======================================,")
#pragma message("       `^^^^^^^^^^^^^^^^^^^ /-------------------------------------\"")
#pragma message("            Katana Engine \\/ © 2012 - Shuriken Studios LLC")
#pragma message("")


/* Standard Headers */
#include <stdlib.h>
#include <malloc.h>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <limits>
#include <map>


/* Allegro */
#include <allegro5\allegro.h>
#include <allegro5\allegro_native_dialog.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_audio.h>
#include <allegro5\allegro_acodec.h>
#include <allegro5\allegro_primitives.h>


/* Timing */
#include "GameTime.h"


/* Math */
#include "MathUtil.h"
#include "Color.h"
#include "Point.h"
#include "Vector2.h"
#include "Region.h"
#include "Primitive.h"
#include "Line.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Bezier.h"


/* Input Handling */
#include "KeyState.h"
#include "GamepadState.h"
#include "MouseState.h"
#include "InputState.h"


/* Resource Management */
#include "Resource.h"
#include "Font.h"
#include "Texture.h"
#include "Animation.h"
#include "ResourceManager.h"


/* Graphics Management */
#include "RenderTarget.h"
#include "SpriteBatch.h"


/* Interfaces */
#include "IService.h"



/* Particle Management */
#include "IComponentInterfaces.h"		// Core
#include "Particle.h"

#include "DefaultInitializer.h"			// Initializers
#include "ColorInitializer.h"
#include "AlphaInitializer.h"
#include "ScaleInitializer.h"
#include "VelocityInitializer.h"
#include "AccelerationInitializer.h"
#include "RandomLifespanInitializer.h"
#include "RandomRotationInitializer.h"
#include "RandomPositionInitializer.h"
#include "RandomVelocityInitializer.h"
#include "RandomAngularVelocityInitializer.h"

#include "DefaultUpdater.h"				// Updaters
#include "ColorUpdater.h"
#include "AlphaUpdater.h"
#include "VelocityUpdater.h"
#include "AccelerationUpdater.h"
#include "AngularVelocityUpdater.h"
#include "RandomVelocityUpdater.h"
#include "RotationAlignUpdater.h"
#include "TargetUpdater.h"

#include "DefaultRenderer.h"			// Renderers
#include "TextureRenderer.h"

#include "ParticleTemplate.h"			// Managment
#include "ParticleManager.h"
#include "ParticleEmitter.h"


/* Screen Management */
#include "MenuItem.h"
#include "Screen.h"
#include "MenuScreen.h"
#include "ScreenManager.h"


/* GUI */
#include "EventHandlers.h"
#include "Component.h"
#include "ComponentCollection.h"
#include "Panel.h"
#include "Toggle.h"
#include "Slider.h"
#include "ResizablePanel.h"
#include "Theme.h"

/* Game Engine */
#include "GameTime.h"
#include "ServiceContainer.h"
#include "Game.h"
