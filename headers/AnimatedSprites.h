#ifndef ANIMATEDSPRITES_H_
#define ANIMATEDSPRITES_H_

#include <map>
#include <string>
#include <vector>


#include "Sprites.h"
#include "Global.h"

class Graphics;


/*
** AnimatedSprite class
**
** Holds logic for animating sprites
*/

class AnimatedSprite : public Sprite {
public:
    AnimatedSprite();
    AnimatedSprite(Graphics &graphics, const std::string &filePath,
	int sourceX, int sourceY, int width, int height, float posX,
                   float posY, float timeToUpdate);


    /*
    ** void playAnimation
    ** Plays the animation proviode if it's not already playing
     */
    void playAnimation(std::string animation, bool once = false);

    /*
    ** void update
    **
    ** Updates the animated sprites (timer)
     */
    void update(int elapsedTime);

    /*
     * void draw
     *
     * Draws the sprite to the screen
     * */
    void draw(Graphics &graphics, int x, int y);

    /*
    ** void setupAnimation
    ** A required function that sets up all animation for a sprite
     */
    virtual void setupAnimations();

protected:
    double _timeToUpdate;
    bool _currentAnimationOnce;
    std::string _currentAnimation;

    /* void addAnimation
    ** Adds an animation to the map of animations for the sprite
     */
    void addAnimation(int frames, int x, int y, std::string name, int width, int height, Vector2 offset);

    /*
    ** void resetANimations
    ** Reset all animations associated with this sprite
     */
    void resetAnimations();


    /*
    ** Stops the current animation
     */
    void stopAnimation();

    /*
    ** steVisible
    **
    ** Changes the visibility of the animated sprites
     */
    void setVisible(bool visible);

    /*
    ** Logic that happens when the animation ends
     */
    virtual void animationDone(std::string currentAnimation);

private:
    std::map<std::string, std::vector<SDL_Rect>> _animations;
    std::map<std::string, Vector2> _offsets;

    int _frameIndex;
    int _timeElapsed;
    bool _visible;
};

#endif // ANIMATEDSPRITES_H_
