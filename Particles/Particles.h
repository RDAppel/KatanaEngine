
#pragma once

#include "KatanaEngine.h"

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
#include "ScaleUpdater.h"
#include "VelocityUpdater.h"
#include "RotationUpdater.h"
#include "RotationAlignUpdater.h"
#include "TargetUpdater.h"

#include "DefaultRenderer.h"			// Renderers
#include "TextureRenderer.h"

#include "ParticleTemplate.h"			// Managment
#include "ParticleManager.h"
#include "ParticleEmitter.h"
