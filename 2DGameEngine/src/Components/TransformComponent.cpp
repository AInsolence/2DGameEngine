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
	// TODO: make update with delta function
}

void TransformComponent::Render()
{
	SDL_Rect TransformRectangle = SDL_Rect{static_cast<int>(Position.x),
										   static_cast<int>(Position.y),
										   Width,
										   Height};
	SDL_SetRenderDrawColor(Game::Renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(Game::Renderer, &TransformRectangle);
}
