#ifndef MAP_H
#define MAP_H

#include <string>
/**
*	This class reads map from the source file, adds all
*	received tiles with a @link TileComponent @endlink
*	as an @link Entity @endlink to the @link EntityManager @endlink.
*/
class Map
{
public:
	Map(std::string _SourceTextureId, int _Size, float _Scale);
	~Map();

	// Load Map from a source image
	void Load(const std::string& FilePath, int SizeX, int SizeY);
	// Add tile created from a Map source texture
	void AddTile(int SourceX, int SourceY, float PositionX, float PositionY);

private:
	std::string SourceTextureId;
	int TileSize;
	float Scale;
};

#endif