#ifndef GAME_H_
#define GAME_H_

#include "AnimatedSprites.h"

class Graphics;

class Game {
public:
	Game();
	~Game();

private:
    void gameLoop();
    void draw(Graphics &graphics);
    void update(float elapsedTime);

    AnimatedSprite _player;
};

#endif // GAME_H_
