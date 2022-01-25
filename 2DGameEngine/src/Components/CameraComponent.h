#ifndef CAMERACOMPONENT_H
#define CAMERACOMPONENT_H

#include<memory>
#include "SDL.h"

#include "../Core/Component.h"

class TransformComponent;
class GameInstance;

enum class ECameraType
{
	PlayerFollowing,
	Static
};

class CameraComponent : public Component
{
public:

	CameraComponent(ECameraType _CameraType = ECameraType::PlayerFollowing);

	virtual void Update(float DeltaTime) override;
	virtual void Initialize() override;

	SDL_Rect Camera;
	ECameraType CameraType;
	
protected:
	std::shared_ptr<TransformComponent> TransformComp;
};

#endif
