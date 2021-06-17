#include "TransformComponent.h"
#include "../Game.h"
#include <SDL.h>

TransformComponent::TransformComponent(int posX, int posY, int velX, int velY, int _width, int _height, float _scale)
{
	Position.x = posX;
	Position.y = posY;
	Velocity.x = velX;
	Velocity.y = velY;
	Width = _width;
	Height = _height;
	Scale = _scale;
}

void TransformComponent::Initialize()
{
}

void TransformComponent::Update(float DeltaTime)
{
	Position.x += Velocity.x * DeltaTime;
	Position.y += Velocity.y * DeltaTime;
}
