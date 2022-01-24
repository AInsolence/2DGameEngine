#ifndef SPRITECOMPONENT_H
#define SPRITECOMPONENT_H

#include <memory>
#include <string>
#include <map>
#include <SDL2/include/SDL.h>
#include "../Core/Component.h"
#include "Animation.h"

class TransformComponent;
/**
*	This class extends @link Component @endlink class as
*	a sprite component for an @link Entity @endlink. There are
*	a container for @link Animation @endlink and update functionality. 
*	Sprite component includes @link TransformComponent @endlink  
*	@link SDL_Texture @endlink references.
*/
class SpriteComponent : public Component
{
public:
	SpriteComponent(const std::string& FilePath, int _RelativeZOrder = 0);
	SpriteComponent(const std::string& FilePath,
					unsigned int _NumberOfFrames, 
					unsigned int _AnimSpeed, 
					bool _HasDirection,
					bool _isFixedPosOnScreen,
					int _RelativeZOrder = 0);

	void Initialize() override;
	void SetTexture(const std::string& AssetTextureID);
	void Update(float DeltaTime) override;
	void Render() override;
	void PlayAnimation(const std::string& AnimName);

	SDL_RendererFlip Flip;

private:
	std::shared_ptr<TransformComponent> TransformComp;
	std::shared_ptr<SDL_Texture> Texture;
	SDL_Rect SourceRect;
	SDL_Rect DestinationRect;

	// Animation
	bool isAnimated;
	bool isFixedPosOnScreen;
	unsigned int NumberOfFrames;
	unsigned int AnimSpeed;
	unsigned int AnimationIndex;

	std::string CurrentAnimationName;
	std::map<std::string, class Animation> Animations;
};

#endif