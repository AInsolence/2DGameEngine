#include "TextureManager.h"

std::shared_ptr<SDL_Texture> TextureManager::LoadTexture(const char* FileName)
{
    SDL_Surface* Surface = IMG_Load(FileName);
    std::shared_ptr<SDL_Texture> Texture(SDL_CreateTextureFromSurface
                                                 (Game::Renderer.get(),Surface),
                                                                    SDL_DestroyTexture);
    SDL_FreeSurface(Surface);

    return Texture;
}

void TextureManager::Draw(std::shared_ptr<SDL_Texture> Texture,
                          SDL_Rect SourceRect, 
                          SDL_Rect DestinationRect, 
                          SDL_RendererFlip Flip)
{
    SDL_RenderCopyEx(Game::Renderer.get(),
                     Texture.get(),
                     &SourceRect,
                     &DestinationRect,
                     0.0,
                     NULL, 
                     Flip);
}
