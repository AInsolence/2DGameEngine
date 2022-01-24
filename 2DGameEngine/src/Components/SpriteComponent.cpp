#include "SpriteComponent.h"
#include "TransformComponent.h"
#include "../Game.h"
#include "../Managers/AssetManager.h"
#include "../Managers/TextureManager.h"
#include <iostream>

SpriteComponent::SpriteComponent(const std::string& FilePath, int _RelativeZOrder)
{
	Flip = SDL_FLIP_NONE;

	isAnimated = false;
	isFixedPosOnScreen = false;

	NumberOfFrames = 0;
	AnimSpeed = 0;
	AnimationIndex = 0;
	RelativeZOrder = _RelativeZOrder;

	SetTexture(FilePath);
}

SpriteComponent::SpriteComponent(const std::string& FilePath,
                                 unsigned int _NumberOfFrames, 
                                 unsigned int _AnimSpeed, 
                                 bool _HasDirection, 
                                 bool _isFixedPosOnScreen,
                                 int _RelativeZOrder)
{
	Flip = SDL_FLIP_NONE;

	isAnimated = true;
	NumberOfFrames = _NumberOfFrames;
	AnimSpeed = _AnimSpeed;
	isFixedPosOnScreen = _isFixedPosOnScreen;
	RelativeZOrder = _RelativeZOrder;

	if (_HasDirection)
	{
		auto DownAnimation = Animation(0, NumberOfFrames, AnimSpeed);
		auto RightAnimation = Animation(1, NumberOfFrames, AnimSpeed);
		auto LeftAnimation = Animation(2, NumberOfFrames, AnimSpeed);
		auto UpAnimation = Animation(3, NumberOfFrames, AnimSpeed);

		Animations.emplace("DownAnimation", DownAnimation);
		Animations.emplace("RightAnimation", RightAnimation);
		Animations.emplace("LeftAnimation", LeftAnimation);
		Animations.emplace("UpAnimation", UpAnimation);

		CurrentAnimationName = "DownAnimation";
		AnimationIndex = 0;
	}
	else
	{
		auto SingleAnimation = Animation(0, NumberOfFrames, AnimSpeed);
		Animations.emplace("SingleAnimation", SingleAnimation);
		AnimationIndex = 0;
		CurrentAnimationName = "SingleAnimation";
	}

	PlayAnimation(CurrentAnimationName);
	SetTexture(FilePath);
}

void SpriteComponent::Initialize()
{
	TransformComp = Owner->GetComponent<TransformComponent>();
	SourceRect.x = 0;
	SourceRect.y = 0;
	SourceRect.w = TransformComp->Width;
	SourceRect.h = TransformComp->Height;
}

void SpriteComponent::SetTexture(const std::string& AssetTextureID)
{
	Texture = Game::AssetsManager->GetTexture(AssetTextureID);
}

void SpriteComponent::Update(float DeltaTime)
{
	if (isAnimated)
	{
		SourceRect.x = SourceRect.w * static_cast<int>(SDL_GetTicks() / AnimSpeed % NumberOfFrames);
	}
	SourceRect.y = AnimationIndex * TransformComp->Height;

	DestinationRect.x = static_cast<int>(TransformComp->Position.x);
	DestinationRect.y = static_cast<int>(TransformComp->Position.y);
	DestinationRect.w = TransformComp->Width * TransformComp->Scale;
	DestinationRect.h = TransformComp->Height * TransformComp->Scale;
}

void SpriteComponent::Render()
{
	TextureManager::Draw(Texture, SourceRect, DestinationRect, Flip);
}

void SpriteComponent::PlayAnimation(const std::string& AnimName)
{
	CurrentAnimationName = AnimName;
	AnimationIndex = Animations[AnimName].Index;
	AnimSpeed = Animations[AnimName].AnimSpeed;
	NumberOfFrames = Animations[AnimName].NumberOfFrames;
}
