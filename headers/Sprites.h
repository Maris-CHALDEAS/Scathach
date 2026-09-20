#ifndef SPRITES_H_
#define SPRITES_H_

#include <SDL2/SDL.h>
#include <string>
/*
** Sprite class
** Holds all the information for individual sprites
 */

class Graphics;

class Sprite {
public:
    Sprite();
    Sprite(Graphics &graphics, const std::string &filePath, int sourceX,
           int sourceY, int width, int height, float posX, float posY);

    virtual ~Sprite();
    virtual void update();
    void draw(Graphics &graphics, int x, int y);

protected:
    SDL_Rect _sourceRect;
    SDL_Texture* _spriteSheet;

    float _x, _y;
};

#endif // SPRITES_H_
