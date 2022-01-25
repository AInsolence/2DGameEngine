#include "TileComponent.h"

#include "CameraComponent.h"
#include "../Managers/AssetManager.h"
#include "../Managers/CameraManager.h"

TileComponent::TileComponent(int SourceRectX, 
                             int SourceRectY, 
                             float PositionX, 
                             float PositionY, 
                             int TileSize, 
                             float TileScale, 
                             const std::string& AssetTextureId)
{
	Texture = GameInstance::AssetsManager->GetTexture(AssetTextureId);

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
	if (GameInstance::CamerasManager->GetPlayersWithCamera()[0])
	{
		// Update tile render relative to the player's camera
		DestinationRect.x = Position.x - GameInstance::CamerasManager->GetPlayersWithCamera()[0]->GetComponent<CameraComponent>()->Camera.x;
		DestinationRect.y = Position.y - GameInstance::CamerasManager->GetPlayersWithCamera()[0]->GetComponent<CameraComponent>()->Camera.y;
	}
}

void TileComponent::Render()
{
	TextureManager::Draw(Texture, SourceRect, DestinationRect);
}
