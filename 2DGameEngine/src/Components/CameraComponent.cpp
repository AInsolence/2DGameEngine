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
	}
}

void CameraComponent::Initialize()
{
	GameInstance::CamerasManager->AddPlayerWithCamera(Owner);
	TransformComp = Owner->GetComponent<TransformComponent>();
	
	Camera.x = 0;
	Camera.y = 0;
	Camera.w = TransformComp->Width;
	Camera.h = TransformComp->Height;
}
