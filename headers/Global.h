#ifndef GLOBAL_H_
#define GLOBAL_H_

namespace Globals {
    const int SCREEN_WIDTH = 1500;
    const int SCREEN_HEIGHT = 960;

    const float SPRITE_SCALE = 2.0f;
}

struct Vector2 {

	int x, y;

	Vector2()
	    : x(0), y(0)
    {}

    Vector2(int x, int y)
        : x(x), y(y)
    {}

    Vector2 zero()
    {
        return Vector2(0,0);
    }
};

#endif // GLOBAL_H_
