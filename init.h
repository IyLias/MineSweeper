#ifndef   _INIT_H_
#define   _INIT_H_

#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

//Texture wrapper class
class LTexture
{
public:
	//Initializes variables
	LTexture();

	//Deallocates memory
	~LTexture();

	//Loads image at specified path
	bool loadFromFile(std::string path);

	//Creates image from font string
	bool loadFromRenderedText(std::string textureText, SDL_Color textColor);

	//Deallocates texture
	void free();

	//Set color modulation
	void setColor(Uint8 red, Uint8 green, Uint8 blue);

	//Set blending
	void setBlendMode(SDL_BlendMode blending);

	//Set alpha modulation
	void setAlpha(Uint8 alpha);

	//Renders texture at given point
	void render(int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

	//Gets image dimensions
	int getWidth();
	int getHeight();

private:
	//The actual hardware texture
	SDL_Texture* mTexture;

	//Image dimensions
	int mWidth;
	int mHeight;
};

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//Starts up SDL and creates window
bool init();


SDL_Texture* loadTexture(const char* path, SDL_Renderer* renderer);


//Screen dimension constants
const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 600;

//The window we'll be rendering to
extern SDL_Window* gWindow;

//The window renderer
extern SDL_Renderer* gRenderer;

//Globally used font
extern TTF_Font *gFont;

//Rendered texture
extern LTexture gTextTexture;

extern Mix_Chunk * Move_Back_Sound;

extern Mix_Chunk * Move_START_Sound;

extern Mix_Chunk * Move_Select_Sound;

extern Mix_Chunk * Boom_Sound;

extern Mix_Chunk * Clear_Sound;


typedef struct
{
	int r;
	int g;
	int b;

}Color;



#endif // !  _INIT_H_
