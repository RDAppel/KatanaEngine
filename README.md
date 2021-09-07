# KatanaEngine
C++ Game Framework built on the Allegro Library (http://liballeg.org/)

# Notes
To Add a Project:
 - Add reference to KatanaEngine Project
 - Properties > C/C++ > Additional include directories (add "..\KatanaEngine")
 - Manage NuGet Packages - Allegro 5
 - Properties > Allegro ("Yes" to all used addons)
 - Change Startup Project
 - Properties > C/C++ > Precompiled Headers (create and set to use)


 # To do

 Fix Bug:
	Test Project: GUI not rendering sometimes

  Helper function in resource?
   -- parse ints and floats into arrays

   -- constructors using array parameters
     -- primitive types
	 -- vec2/point
	 -- region
	 -- color

 Think through unloading resources...
	specifically how cached resources can't be unloaded
	==> cached resources should be marked as cached = true
		then when they are being destroyed they can have the
		resource manager remove them
    ==> what about clones then?

 Shader Support
 -- Game.cpp -- ALLEGRO_PROGRAMMABLE_PIPELINE
 -- Create and use "default" shaders
 -- Function (or class ?) to load and use non-default shaders

 Animation class
	-- auto load image (optional)
		-- look at Font as example
	-- update to use Region::TryParse


 Particles
	Update to honor SRP (split updaters and initializers... and renderers?)

 Templates
	PARTICLE COMPONENTS!!!
	Game Project? (At least Game class)
	Screen (Template for ALL callback functions) ...easier to delete than look them up
	Menu   (Template for ALL callback functions)




