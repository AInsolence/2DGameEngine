#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include <memory>
#include <map>
#include <string>
#include "TextureManager.h"

class EntityManager;

/**
*	This class stores all @link SDL_Texture @endlink in a container 
*	and provide the API to get/add new one.
*/
class AssetManager
{
public:
	AssetManager();
	~AssetManager(){};

	void AddTexture(const std::string& TextureId, const char* FilePath);
	std::shared_ptr<SDL_Texture> GetTexture(const std::string& TextureId);
	void ClearData();

private:
	std::map<std::string, std::shared_ptr<SDL_Texture>> Textures;
};

#endif