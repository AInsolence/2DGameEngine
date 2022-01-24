#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <memory>
#include "../GameInstance.h"

/**
*	This class provides static methods to LoadTexture()
*   @link SDL_Texture @endlink from a file and render(Draw()) it
*/

class TextureManager
{
public:
	static std::shared_ptr<SDL_Texture> LoadTexture(const char* FileName);
	static void Draw(std::shared_ptr<SDL_Texture> Texture,
					 SDL_Rect SourceRect,
					 SDL_Rect DestinationRect, 
					 SDL_RendererFlip Flip = SDL_FLIP_NONE);
};

#endif