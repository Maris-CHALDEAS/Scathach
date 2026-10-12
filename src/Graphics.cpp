#include <SDL2/SDL.h>
#include <SDL2/SDL_filesystem.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_image.h>
#include <cstdio>

#include "../headers/Graphics.h"
#include "../headers/Global.h"
/*
 * Graphics class
 * Holds all information dealing with graphics for the game
*/

Graphics::Graphics()
{
    SDL_CreateWindowAndRenderer(Globals::SCREEN_WIDTH,Globals::SCREEN_HEIGHT,0,&this->_window,&this->_renderer);
    SDL_SetWindowTitle(this->_window, "Scathach");

    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags)) {
        printf("\nSDL_image could not be initialized\n");
    }

}

Graphics::~Graphics()
{
	SDL_DestroyRenderer(this->_renderer);
	SDL_DestroyWindow(this->_window);
	IMG_Quit();
}


std::string Graphics::getBasePath()
{
	char *base = SDL_GetBasePath();
	std::string basePath(base);
	SDL_free(base);
	return basePath;
}

SDL_Surface *Graphics::loadImage(const std::string &filepath)
{
	if (this->_spriteSheets.count(filepath) == 0) {
        std::string fullPath = this->getBasePath() + filepath;
        this->_spriteSheets[filepath] = IMG_Load(fullPath.c_str());
	}
	return this->_spriteSheets[filepath];
}


void Graphics::blitSurface(SDL_Texture *texture, SDL_Rect *sourceRectange,
    SDL_Rect *destinationRectange)
{
    SDL_RenderCopy(this->_renderer, texture, sourceRectange, destinationRectange);
}

void Graphics::flip()
{
    SDL_RenderPresent(this->_renderer);
}

void Graphics::clear()
{
    SDL_RenderClear(this->_renderer);
}

SDL_Renderer *Graphics::getRenderer() const
{
    return this->_renderer;
}
