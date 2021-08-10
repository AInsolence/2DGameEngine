#ifndef TILECOMPONENT_H
#define TILECOMPONENT_H

#include "../Core/Component.h"

#include <memory>
#include <string>
#include <SDL.h>
#include <glm/glm.hpp>

class TileComponent : public Component
{
public:
	TileComponent(int SourceRectX, 
				  int SourceRectY,
				  float PositionX,
				  float PositionY,
				  int TileSize,
				  float TileScale,
				  const std::string& AssetTextureId);

	~TileComponent();

	void Update(float DeltaTime) override;
	void Render() override;

protected:
	std::shared_ptr<SDL_Texture> Texture;
	SDL_Rect SourceRect;
	SDL_Rect DestinationRect;
	glm::vec2 Position;
};

#endif