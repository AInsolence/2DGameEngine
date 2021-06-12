#ifndef TEXTUREMANAGER.H
#define TEXTUREMANAGER.H

#include "src/Game.h"

class TextureManager
{
	static SDL_Texture* LoadTexture(const char* FileName);
	static void Draw(SDL_Texture* Texture, 
					 SDL_Rect SourceRect, 
					 SDL_Rect DestinationRect, 
					 SDL_RendererFlip Flip);
};

#endif