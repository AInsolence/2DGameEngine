#include "TransformComponent.h"
#include "../Game.h"
#include <SDL.h>
#include <iostream>

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

void TransformComponent::Render()
{
	SDL_Rect TransformRectangle = SDL_Rect{static_cast<int>(Position.x),
										   static_cast<int>(Position.y),
										   Width,
										   Height};
	SDL_SetRenderDrawColor(Game::Renderer.get(), 255, 255, 255, 255);
	SDL_RenderFillRect(Game::Renderer.get(), &TransformRectangle);

	std::cout << "Rect created and might be rendered" << std::endl;
	// Swap render buffers
	SDL_RenderPresent(Game::Renderer.get());
}
