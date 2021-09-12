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

 Factory functions for GUI?

commenting... make sure that all .h files have doxygen comments

 Shader Support
 -- Game.cpp -- ALLEGRO_PROGRAMMABLE_PIPELINE
 -- Create and use "default" shaders
 -- Function (or class ?) to load and use non-default shaders

 Templates
	Game Project? (At least Game class)
	Screen (Template for ALL callback functions) ...easier to delete than look them up
	Menu   (Template for ALL callback functions)




