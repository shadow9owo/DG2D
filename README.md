# DG2D | pre alpha 1.1
DoomGames2D TOOLKIT (FOR SDL2!)
<br>
<br>
components :<br>
-  Smart Table DB (STD) - simple plug n play save system for c++ [DEPRECATED!!!!]
-  SDL event wrapper
-  SDL raylib like texture wrapper

features :
- save file support
- event wrapper
- math utils
- texture wrapper
- audio wrapper
- ttf wrapper
- ini wrapper
- deltatime
  
to do (in no specific order) :
- UI wrappers
- write actual documentation
- spritesheet support
- UI for setting up spritesheets
- tilemap support
- web support (emscripten)
- tiled integration or equivalent

more in Ideas.md

how to use?
- git clone repository
- and compile

(requires SDL2,SDL_image,SDL_mixer,SDL_ttf)

how to enable debugging
- compile with the -DDEBUG flag set to 1 and then the utils.cpp isdebugbuild class will return true and affected functions will log data
