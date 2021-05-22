#include "Game.h"
#include <iostream>
#include "Constants.h"
#include "../lib/glm/glm.hpp"

Game::Game()
{
	bIsRunning = false;
}

Game::~Game()
{
}

bool Game::IsRunning() const
{
	return bIsRunning;
}

void Game::Initialize(int width, int height)
{	
	// Init SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		std::cerr << "Error: Game.cpp SDL inialization failed." << std::endl;
		return;
	}
	// Create game window
	Window = SDL_CreateWindow("2DGameEngineWindow", 
								SDL_WINDOWPOS_CENTERED, 
								SDL_WINDOWPOS_CENTERED,
								width,
								height,
								0);
	if (!Window)
	{
		std::cerr << "Error: Game.cpp Window initialization failed";
		return;
	}
	// Create renderer. -1 parameter means to use standard render driver
	Renderer = SDL_CreateRenderer(Window, -1, 0);
	if (!Renderer)
	{
		std::cerr << "Error: Game.cpp Renderer initialization failed";
		return;
	}

	bIsRunning = true;
	return;
}


void Game::ProcessInput()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		bIsRunning = false;
		break;
	case SDL_KEYDOWN:
		if (event.key.keysym.sym == SDLK_ESCAPE)
		{
			bIsRunning = false;
		}
		break;
	default:
		break;
	}
}

glm::vec2 projectilePos = glm::vec2(0.0f, 0.0f);
glm::vec2 projectileVel = glm::vec2(30.f, 20.f);

void Game::Update()
{
	// Wait a calculated amount of ms if the current time is not equal time per frame
	int TimeToWait = FRAME_TARGET_TIME - (SDL_GetTicks() - TicksLastFrame);
	
	if (TimeToWait > 0 && TimeToWait <= FRAME_TARGET_TIME)
	{
		SDL_Delay(TimeToWait);
	}

	// Delta time is the difference in ticks from the last frame
	float DeltaTime = (SDL_GetTicks() - TicksLastFrame) / 1000.f;

	// Sets the new ticks for the current frame to be used in the next pass
	TicksLastFrame = SDL_GetTicks();

	// Clamp DeltaTime to a maximum value
	DeltaTime = (DeltaTime > 0.05f) ? 0.05f : DeltaTime;

	projectilePos = glm::vec2(projectilePos.x + projectileVel.x * DeltaTime,
							  projectilePos.y + projectileVel.y * DeltaTime);
}

void Game::Render()
{
	// Set color and clear all canvas with it (re-draw background)
	SDL_SetRenderDrawColor(Renderer, 21, 21, 21 , 255);
	SDL_RenderClear(Renderer);
	// Create projectile rectangle
	SDL_Rect Projectile
	{
		static_cast<int>(projectilePos.x),
		static_cast<int>(projectilePos.y),
		10,
		10
	};
	// Set color and draw rectangle
	SDL_SetRenderDrawColor(Renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(Renderer, &Projectile);
	// Swap render buffers
	SDL_RenderPresent(Renderer);
}

void Game::Destroy()
{
	SDL_DestroyRenderer(Renderer);
	SDL_DestroyWindow(Window);
	SDL_Quit();
}
