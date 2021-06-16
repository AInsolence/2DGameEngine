#include "Game.h"
#include <iostream>
#include "Constants.h"
#include "Components/TransformComponent.h"
#include "Components/SpriteComponent.h"
#include "../lib/glm/glm.hpp"
#include "Managers/EntityManager.h"
#include "Managers/AssetManager.h"

std::unique_ptr<SDL_Renderer, std::function<void(SDL_Renderer*)>> Game::Renderer;
std::unique_ptr<AssetManager> Game::AssetsManager;

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
	Window = std::unique_ptr<SDL_Window, std::function<void(SDL_Window*)>>
								(SDL_CreateWindow("2DGameEngineWindow",
								SDL_WINDOWPOS_CENTERED,
								SDL_WINDOWPOS_CENTERED,
								width,
								height,
								0), SDL_DestroyWindow);
	if (!Window)
	{
		std::cerr << "Error: Game.cpp Window initialization failed";
		return;
	}
	// Create renderer. -1 parameter means to use standard render driver
	Renderer = std::unique_ptr<SDL_Renderer, std::function<void(SDL_Renderer*)>>
					(SDL_CreateRenderer(Window.get(), -1, 0), SDL_DestroyRenderer);
	if (!Renderer)
	{
		std::cerr << "Error: Game.cpp Renderer initialization failed";
		return;
	}

	// Create managers
	Manager = std::make_shared<EntityManager>(EntityManager());
	if (Manager)
	{
		AssetsManager = std::make_unique<AssetManager>(AssetManager(Manager));
	}
	
	
	// Load level data
	LoadLevel(0);

	bIsRunning = true;
	return;
}

void Game::LoadLevel(unsigned int LevelNumber)
{
	// TODO Only in debug mode
	std::cout << SDL_GetBasePath() << std::endl;
	// Load textures to AssetsManager
	std::string tankTextureFilePath = "assets/images/tank-big-right.png";
	AssetsManager->AddTexture("tank-big-right", tankTextureFilePath.c_str());

	// Create entities and components
	Entity& Tank(Manager->AddEntity("Tank"));
	Tank.AddComponent<TransformComponent>(0, 0, 10, 20, 32, 32, 1.f);
	Tank.AddComponent<SpriteComponent>("tank-big-right");

	auto Transform = Tank.GetComponent<TransformComponent>();
	if (Transform)
	{
		std::cout << Transform->Height;
	}
}

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

	Manager->Update(DeltaTime);
}

void Game::Render()
{
	// Set color and clear all canvas with it (re-draw background)
	SDL_SetRenderDrawColor(Renderer.get(), 21, 21, 21, 255);
	SDL_RenderClear(Renderer.get());
	// Render all entities on the level
	if (!Manager->HasNoEntities())
	{
		Manager->Render();
	}
	// Swap render buffers
	SDL_RenderPresent(Renderer.get());
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

void Game::Destroy()
{
	SDL_Quit();
}
