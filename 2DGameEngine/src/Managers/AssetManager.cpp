#include "AssetManager.h"

AssetManager::AssetManager() 
{
}

void AssetManager::AddTexture(const std::string& TextureId, const char* FilePath)
{
	Textures.emplace(TextureId, TextureManager::LoadTexture(FilePath));
}

std::shared_ptr<SDL_Texture> AssetManager::GetTexture(const std::string& TextureId)
{
	return Textures[TextureId];
}

void AssetManager::ClearData()
{
	Textures.clear();
}
