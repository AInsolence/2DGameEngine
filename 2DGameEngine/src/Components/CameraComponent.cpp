#include "CameraComponent.h"

#include <iostream>

#include "TransformComponent.h"
#include "../GameInstance.h"
#include "../Core/Constants.h"
#include "../Managers/CameraManager.h"

CameraComponent::CameraComponent(ECameraType _CameraType)
{
	Camera = {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT};
	CameraType = _CameraType;
}

void CameraComponent::Update(float DeltaTime)
{
	if (CameraType == ECameraType::PlayerFollowing)
	{
		Camera.x = TransformComp->Position.x - (WINDOW_WIDTH / 2);
		Camera.y = TransformComp->Position.y - (WINDOW_HEIGHT / 2);
		// Clamp camera on the map
		Camera.x = Camera.x < 0 ? 0 : Camera.x;
		Camera.y = Camera.y < 0 ? 0 : Camera.y;
		Camera.x = Camera.x > Camera.w ? Camera.w : Camera.x;
		Camera.y = Camera.y > Camera.h ? Camera.h : Camera.y;
	}
}

void CameraComponent::Initialize()
{
	GameInstance::CamerasManager->AddPlayerWithCamera(Owner);
	TransformComp = Owner->GetComponent<TransformComponent>();
	
	Camera.x = 0;
	Camera.y = 0;
	Camera.w = WINDOW_WIDTH;
	Camera.h = WINDOW_HEIGHT;
}
