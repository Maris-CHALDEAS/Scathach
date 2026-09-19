
#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>

#include "../headers/Graphics.h"

/*
 * Graphics class
 * Holds all information dealing with graphics for the game
*/

Graphics::Graphics()
{
    SDL_CreateWindowAndRenderer(640,480,0,&this->_window,&this->_renderer);
    SDL_SetWindowTitle(this->_window, "Scathach");
}

Graphics::~Graphics()
{
	SDL_DestroyRenderer(this->_renderer);
    SDL_DestroyWindow(this->_window);
}
