#ifndef SPRITECOMPONENT_H
#define SPRITECOMPONENT_H

#include <memory>
#include <string>
#include <map>
#include <SDL2/include/SDL.h>
#include "../Component.h"
#include "Animation.h"

class TransformComponent;

class SpriteComponent : public Component
{
public:
	SpriteComponent(std::string FilePath);
	SpriteComponent(std::string FilePath, 
					unsigned int _NumberOfFrames, 
					unsigned int _AnimSpeed, 
					bool _HasDirection,
					bool _isFixedPosOnScreen);

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

	// Animation
	void PlayAnimation(std::string& const);

	bool isAnimated = false;
	bool isFixedPosOnScreen = false;
	unsigned int NumberOfFrames = 0;
	unsigned int AnimSpeed = 0;
	unsigned int AnimationIndex = 0;

	std::string CurrentAnimationName;
	std::map<std::string, class Animation> Animations;
};

#endif