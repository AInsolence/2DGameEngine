#include "CameraManager.h"

#include <iostream>

const std::vector<std::shared_ptr<Entity>>& CameraManager::GetPlayersWithCamera() const
{
	return PlayersWithCamera;
}

void CameraManager::AddPlayerWithCamera(Entity* PlayerWithCamera)
{
	PlayersWithCamera.emplace_back(PlayerWithCamera);
}
