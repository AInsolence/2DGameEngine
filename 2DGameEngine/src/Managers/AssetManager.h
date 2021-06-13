#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include <memory>
#include <map>
#include <string>

#include "EntityManager.h"
#include "TextureManager.h"

class EntityManager;

class AssetManager
{
public:
	AssetManager(std::shared_ptr<EntityManager>);
	~AssetManager(){};

	void AddTexture(std::string TextureId, const char* FilePath);
	std::shared_ptr<SDL_Texture> GetTexture(std::string TextureId);
	void ClearData();

private:
	std::shared_ptr<EntityManager> Manager;
	std::map<std::string, std::shared_ptr<SDL_Texture>> Textures;
};

#endif