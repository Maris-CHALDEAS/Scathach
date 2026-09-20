#include "../headers/Sprites.h"
#include "../headers/Graphics.h"
#include "../headers/Global.h"
#include <SDL2/SDL_render.h>
#include <cstdio>


Sprite::Sprite()
{}

Sprite::Sprite(Graphics &graphics, const std::string &filePath, int sourceX,
    int sourceY, int width, int height, float posX, float posY)
    : _x(posX), _y(posY)
{
	this->_sourceRect.x = sourceX;
	this->_sourceRect.y = sourceY;
    this->_sourceRect.w = width;
    this->_sourceRect.h = height;


    this->_spriteSheet = SDL_CreateTextureFromSurface(graphics.getRenderer(), graphics.loadImage(filePath));
    if (this->_spriteSheet == nullptr) {
        printf("\nError: Unable to land image\n");
    }
}

Sprite::~Sprite()
{}

void Sprite::draw(Graphics &graphics, int x, int y)
{

	SDL_Rect destinationRectange = {
	    x, y, static_cast<int>(this->_sourceRect.w * Globals::SPRITE_SCALE), static_cast<int>(this->_sourceRect.h * Globals::SPRITE_SCALE)};
	graphics.blitSurface(this->_spriteSheet, &this->_sourceRect, &destinationRectange);
}

void Sprite::update() {}
