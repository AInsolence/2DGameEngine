#include "Map.h"

#include <fstream>
#include <iostream>

#include "../GameInstance.h"
#include "Entity.h"
#include "../Managers/EntityManager.h"
#include "../Components/TileComponent.h"

Map::Map(std::string _SourceTextureId, int _Size, float _Scale)
{
	SourceTextureId = _SourceTextureId;
	TileSize = _Size;
	Scale = _Scale;
}

Map::~Map()
{
}

void Map::Load(const std::string& FilePath, int SizeX, int SizeY)
{
	std::fstream MapFile;
	MapFile.open(FilePath);

	int Digit;

	for (int y = 0; y < SizeY; y++)
	{
		for (int x = 0; x < SizeX; x++)
		{			
			MapFile >> Digit;// Read digit from the map file

			int SourceRectY = Digit/10 * TileSize; // Tile row position
			int SourceRectX = Digit%10 * TileSize; // Tile column position
			
			// Create the tile
			AddTile(SourceRectX, SourceRectY, x * TileSize * Scale, y * TileSize * Scale);

			//// Skip comma
			MapFile.ignore();
		}
	}
	MapFile.close();
}

void Map::AddTile(int SourceX, int SourceY, float PositionX, float PositionY)
{
	auto& Tile = GameInstance::EntitiesManager->AddEntity("Tile");
	Tile.AddComponent<TileComponent>(SourceX,
									 SourceY,
									 PositionX,
									 PositionY,
									 TileSize,
									 Scale,
									 SourceTextureId);
}
