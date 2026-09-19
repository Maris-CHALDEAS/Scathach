#ifndef GRAPHICS_H_
#define GRAPHICS_H_

/*
 * Graphics class
 * Holds all information dealing with graphics for the game
*/

#include <map>
#include <string>

struct SDL_Window;
struct SDL_Renderer;
struct SDL_Surface;
struct SDL_Texture;
struct SDL_Rect;

class Graphics {
public:
	Graphics();
	~Graphics();

	/*
     *
     * SDL_Surface* loadImage
     * Loads an image into the _spriteSheets map if it doesn't already exits
     * As a result, each image witll only be loaded once
     * Returns the imag efrom the map regardless of whether or not it was loaded
   */
	SDL_Surface* loadImage(const std::string &filePath);



	/*
    ** void blitsurface
    **
    ** Draws a texture to a certain part of the screen
     */
    void blitSurface(SDL_Texture* source, SDL_Rect* sourceRectange, SDL_Rect* destinationRectange);

    /*
    ** void flip
    **
    ** Render everything to the screen
     */
    void flip();


    /*
    ** void clear
    ** Clears the screen
     */
    void clear();


    /*
    ** SDL_Renderer* getRenderer
    ** Returns the renderer
     */
    SDL_Renderer* getRenderer() const;

    std::string getBasePath();
private:
    SDL_Window* _window;
    SDL_Renderer* _renderer;


    std::map<std::string, SDL_Surface*> _spriteSheets;
};

#endif // GRAPHICS_H_
       //
       //
