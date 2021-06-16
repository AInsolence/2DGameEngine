#include "SpriteComponent.h"
#include "TransformComponent.h"
#include "../Game.h"
#include "../Managers/AssetManager.h"
#include "../Managers/TextureManager.h"
#include <iostream>

SpriteComponent::SpriteComponent(const char* FilePath)
{
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

void SpriteComponent::SetTexture(std::string AssetTextureID)
{
	Texture = Game::AssetsManager->GetTexture(AssetTextureID);
}

void SpriteComponent::Update(float DeltaTime)
{
	DestinationRect.x = static_cast<int>(TransformComp->Position.x);
	DestinationRect.y = static_cast<int>(TransformComp->Position.y);
	DestinationRect.w = TransformComp->Width * TransformComp->Scale;
	DestinationRect.h = TransformComp->Height * TransformComp->Scale;
}

void SpriteComponent::Render()
{
	TextureManager::Draw(Texture, SourceRect, DestinationRect, Flip);
}
