#include "TileComponent.h"
#include "../Managers/AssetManager.h"

TileComponent::TileComponent(int SourceRectX, 
							 int SourceRectY, 
							 int PositionX, 
							 int PositionY, 
							 int TileSize, 
							 int TileScale, 
							 const std::string& AssetTextureId)
{
	Texture = Game::AssetsManager->GetTexture(AssetTextureId);

	SourceRect.x = SourceRectX;
	SourceRect.y = SourceRectY;
	SourceRect.h = TileSize;
	SourceRect.w = TileSize;

	DestinationRect.x = PositionX;
	DestinationRect.y = PositionY;
	DestinationRect.h = TileSize * TileScale;
	DestinationRect.w = TileSize * TileScale;

	Position.x = PositionX;
	Position.y = PositionY;
}

TileComponent::~TileComponent()
{
}

void TileComponent::Update(float DeltaTime)
{
}

void TileComponent::Render()
{
	TextureManager::Draw(Texture, SourceRect, DestinationRect);
}