#ifndef SPRITECOMPONENT_H
#define SPRITECOMPONENT_H

#include <memory>
#include <string>
#include <SDL2/include/SDL.h>
#include "../Component.h"

class TransformComponent;

class SpriteComponent : public Component
{
public:
	SpriteComponent(const char* FilePath);
	void Initialize() override;
	void SetTexture(std::string AssetTextureID);
	void Update(float DeltaTime) override;
	void Render() override;

	SDL_RendererFlip Flip = SDL_FLIP_NONE;

private:
	std::shared_ptr<TransformComponent> TransformComp;
	std::shared_ptr<SDL_Texture> Texture;
	SDL_Rect SourceRect;
	SDL_Rect DestinationRect;
};

#endif