#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* FileName)
{
    SDL_Surface* Surface = IMG_Load(FileName);
    SDL_Texture* Texture= SDL_CreateTextureFromSurface(Game::Renderer.get(), Surface);
    SDL_FreeSurface(Surface);

    return Texture;
}

void TextureManager::Draw(SDL_Texture* Texture, 
                          SDL_Rect SourceRect, 
                          SDL_Rect DestinationRect, 
                          SDL_RendererFlip Flip)
{
    SDL_RenderCopyEx(Game::Renderer.get(), 
                     Texture, 
                     &SourceRect, 
                     &DestinationRect, 
                     0.0,
                     NULL, 
                     Flip);
}
