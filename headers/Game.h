#ifndef GAME_H_
#define GAME_H_

#include "Sprites.h";

class Graphics;

class Game {
public:
	Game();
	~Game();

private:
    void gameLoop();
    void draw(Graphics &graphics);
    void update(float elapsedTime);

    Sprite _player;
};

#endif // GAME_H_
