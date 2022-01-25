#ifndef CAMERAMANAGER_H
#define CAMERAMANAGER_H

#include <vector>
#include <memory>

#include "../Core/Entity.h"

/**
 * Class represents a camera manager which control cameras in game.
 */

class CameraManager
{
public:
	const std::vector<std::shared_ptr<Entity>>& GetPlayersWithCamera() const;
	void AddPlayerWithCamera(Entity* PlayerWithCamera);

protected:
	std::vector<std::shared_ptr<Entity>> PlayersWithCamera;
};

#endif
