#include "AssetManager.h"

AssetManager::AssetManager(std::shared_ptr<EntityManager> _Manager) : Manager(_Manager)
{
}

void AssetManager::AddTexture(std::string TextureId, const char* FilePath)
{
	Textures.emplace(TextureId, TextureManager::LoadTexture(FilePath));
}

std::shared_ptr<SDL_Texture> AssetManager::GetTexture(std::string TextureId)
{
	return Textures[TextureId];
}

void AssetManager::ClearData()
{
	Textures.clear();
}
