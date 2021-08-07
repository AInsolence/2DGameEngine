#include "InputComponent.h"
#include "../Game.h"
#include <iostream>

InputComponent::InputComponent(const std::string& _UpKey, 
							   const std::string& _RightKey, 
							   const std::string& _DownKey, 
							   const std::string& _LeftKey, 
							   const std::string& _FireKey)
{
	UpKey = GetSDLKeyStringCode(_UpKey);
	RightKey = GetSDLKeyStringCode(_RightKey);
	DownKey = GetSDLKeyStringCode(_DownKey);
	LeftKey = GetSDLKeyStringCode(_LeftKey);
	FireKey = GetSDLKeyStringCode(_FireKey);
}

void InputComponent::Initialize()
{
	SpriteComp = GetOwner()->GetComponent<SpriteComponent>();
	TransformComp = GetOwner()->GetComponent<TransformComponent>();
}

void InputComponent::Update(float DeltaTime)
{
	if (Game::event.type == SDL_KEYDOWN)
	{
		std::string KeyCode = std::to_string(Game::event.key.keysym.sym);
		std::cout << KeyCode << std::endl;
		if (!KeyCode.compare(UpKey))
		{
			TransformComp->Velocity.y = -1 * TransformComp->Speed;
			TransformComp->Velocity.x = 0;
			SpriteComp->PlayAnimation("UpAnimation");
			std::cout << "UpKey" << std::endl;
		}
		if (!KeyCode.compare(RightKey))
		{
			TransformComp->Velocity.x = TransformComp->Speed;
			TransformComp->Velocity.y = 0;
			SpriteComp->PlayAnimation("RightAnimation");
			std::cout << "RightKey" << std::endl;
		}
		if (!KeyCode.compare(DownKey))
		{
			TransformComp->Velocity.y = TransformComp->Speed;
			TransformComp->Velocity.x = 0;
			SpriteComp->PlayAnimation("DownAnimation");
			std::cout << "DownKey" << std::endl;
		}
		if (!KeyCode.compare(LeftKey))
		{
			TransformComp->Velocity.x = -1 * TransformComp->Speed;
			TransformComp->Velocity.y = 0;
			SpriteComp->PlayAnimation("LeftAnimation");
			std::cout << "LeftKey" << std::endl;
		}
		if (!KeyCode.compare(FireKey))
		{
			// TODO: Fire logic
		}
	}

	if (Game::event.type == SDL_KEYUP)
	{
		std::string KeyCode = std::to_string(Game::event.key.keysym.sym);
		if (KeyCode.compare(UpKey))
		{
			TransformComp->Velocity.y = 0;
		}
		if (KeyCode.compare(RightKey))
		{
			TransformComp->Velocity.x = 0;
		}
		if (KeyCode.compare(DownKey))
		{
			TransformComp->Velocity.y = 0;
		}
		if (KeyCode.compare(LeftKey))
		{
			TransformComp->Velocity.x = 0;
		}
	}
}

std::string InputComponent::GetSDLKeyStringCode(const std::string& _KeyCode)
{
	if (_KeyCode.compare("up") == 0) return "1073741906";
	if (_KeyCode.compare("right") == 0) return "1073741903";
	if (_KeyCode.compare("down") == 0) return "1073741905";
	if (_KeyCode.compare("left") == 0) return "1073741904";
	if (_KeyCode.compare("space") == 0) return "32";

	return std::to_string(static_cast<int>(_KeyCode[0]));
}

