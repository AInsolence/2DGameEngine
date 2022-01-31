#include "InputComponent.h"

#include "../GameInstance.h"
#include "../Core/Constants.h"

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
	if (GameInstance::event.type == SDL_KEYDOWN)
	{
		std::string KeyCode = std::to_string(GameInstance::event.key.keysym.sym);
		
		if (!KeyCode.compare(UpKey))
		{
			if (TransformComp->Position.y > 0)
			{
				TransformComp->Velocity.y = -1 * TransformComp->Speed;
				TransformComp->Velocity.x = 0;
				SpriteComp->PlayAnimation("UpAnimation");
			}
			else
			{
				TransformComp->Velocity.y = 0;
			}
		}
		if (!KeyCode.compare(RightKey))
		{
			if (TransformComp->Position.x < WINDOW_WIDTH * SCREEN_SCALE - TransformComp->Width * TransformComp->Scale)
			{
				TransformComp->Velocity.x = TransformComp->Speed;
				TransformComp->Velocity.y = 0;
				SpriteComp->PlayAnimation("RightAnimation");
			}
			else
			{
				TransformComp->Velocity.x = 0;
			}
		}
		if (!KeyCode.compare(DownKey))
		{
			if (TransformComp->Position.y < WINDOW_HEIGHT * SCREEN_SCALE - TransformComp->Height * TransformComp->Scale)
			{
				TransformComp->Velocity.y = TransformComp->Speed;
				TransformComp->Velocity.x = 0;
				SpriteComp->PlayAnimation("DownAnimation");
			}
			else
			{
				TransformComp->Velocity.y = 0;
			}
		}
		if (!KeyCode.compare(LeftKey))
		{
			if (TransformComp->Position.x > 0)
			{
				TransformComp->Velocity.x = -1 * TransformComp->Speed;
				TransformComp->Velocity.y = 0;
				SpriteComp->PlayAnimation("LeftAnimation");
			}
			else
			{
				TransformComp->Velocity.x = 0;
			}
		}
		if (!KeyCode.compare(FireKey))
		{
			std::cout << "Fire called" << std::endl;
			// TODO: Fire logic
			if (Owner->GetZOrder() == 15)
			{
				Owner->SetZOrder(3);
				TransformComp->Scale = 1.5;
			}
			else
			{
				Owner->SetZOrder(15);
				TransformComp->Scale = 2;
			}
			
		}
	}

	if (GameInstance::event.type == SDL_KEYUP)
	{
		std::string KeyCode = std::to_string(GameInstance::event.key.keysym.sym);
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

