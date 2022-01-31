#include "GameInstance.h"
#include <iostream>
#include "../lib/glm/glm.hpp"
#include "Components/CameraComponent.h"

#include "Core/Map.h"
#include "Core/Constants.h"

#include "Components/TransformComponent.h"
#include "Components/SpriteComponent.h"
#include "Components/InputComponent.h"

#include "Managers/EntityManager.h"
#include "Managers/AssetManager.h"
#include "Managers/CameraManager.h"

std::unique_ptr<SDL_Renderer, std::function<void(SDL_Renderer*)>> GameInstance::Renderer;
std::shared_ptr<EntityManager> GameInstance::EntitiesManager;
std::shared_ptr<AssetManager> GameInstance::AssetsManager;
std::shared_ptr<CameraManager> GameInstance::CamerasManager;
SDL_Event GameInstance::event;

GameInstance::GameInstance()
{
	bIsRunning = false;
	TicksLastFrame = 0;
}

GameInstance::~GameInstance()
{
}

bool GameInstance::IsRunning() const
{
	return bIsRunning;
}

void GameInstance::Initialize(int width, int height)
{	
	// Init SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		std::cerr << "Error: GameInstance.cpp SDL inialization failed." << std::endl;
		return;
	}
	// Create GameInstance's window
	Window = std::unique_ptr<SDL_Window, std::function<void(SDL_Window*)>>
								(SDL_CreateWindow("2DGameInstanceEngineWindow",
								SDL_WINDOWPOS_CENTERED,
								SDL_WINDOWPOS_CENTERED,
								width,
								height,
								0), SDL_DestroyWindow);
	if (!Window)
	{
		std::cerr << "Error: GameInstance.cpp Window initialization failed";
		return;
	}
	// Create renderer. -1 parameter means to use standard render driver
	Renderer = std::unique_ptr<SDL_Renderer, std::function<void(SDL_Renderer*)>>
					(SDL_CreateRenderer(Window.get(), -1, 0), SDL_DestroyRenderer);
	if (!Renderer)
	{
		std::cerr << "Error: GameInstance.cpp Renderer initialization failed";
		return;
	}

	// Create managers
	EntitiesManager = std::make_shared<EntityManager>();
	if (EntitiesManager)
	{
		AssetsManager = std::make_shared<AssetManager>();
		CamerasManager = std::make_shared<CameraManager>();
	}

	// Load level data
	LoadLevel(0);

	bIsRunning = true;
	return;
}

void GameInstance::LoadLevel(unsigned int LevelNumber)
{
	// TODO Only in debug mode
	std::cout << SDL_GetBasePath() << std::endl;
	// Load textures to AssetsManager
	AssetsManager->AddTexture("jungle_map_texture",
						std::string("assets/tilemaps/jungle.png").c_str());
	AssetsManager->AddTexture("tank-big-right", 
						std::string("assets/images/tank-big-right.png").c_str());
	AssetsManager->AddTexture("chopper", 
						std::string("assets/images/chopper-spritesheet.png").c_str());
	AssetsManager->AddTexture("Radar",
						std::string("assets/images/radar.png").c_str());

	// Create entities and components
	std::shared_ptr<Map> JungleMap = std::make_unique<Map>("jungle_map_texture", 32, SCREEN_SCALE);
	JungleMap->Load("assets/tilemaps/jungle_02.csv", 25, 20);


    // Player entity
    auto Player(EntitiesManager->AddEntity("Player"));
    Player->AddComponent<TransformComponent>(300, 0, 0, 0, 32, 32, 1.0f);
    Player->AddComponent<SpriteComponent>("chopper", 2, 60, true, false);
    Player->AddComponent<InputComponent>("up", "right", "down", "left", "space");
	Player->AddComponent<CameraComponent>(ECameraType::PlayerFollowing);
    Player->SetZOrder(3);

	// Tank 1
	auto Tank1(EntitiesManager->AddEntity("Tank1"));
	Tank1->AddComponent<TransformComponent>(0, 0, 10, 20, 32, 32, 1.f);
	Tank1->AddComponent<SpriteComponent>("tank-big-right", false);
	Tank1->SetZOrder(2);

	// Tank 2
	auto Tank2(EntitiesManager->AddEntity("Tank2"));
	Tank2->AddComponent<TransformComponent>(600, 0, -20, 30, 32, 32, 1.f);
	Tank2->AddComponent<SpriteComponent>("tank-big-right");
	Tank2->SetZOrder(2);

	// Radar
	auto Radar(EntitiesManager->AddEntity("Radar"));
	Radar->AddComponent<TransformComponent>(726, 10, 0, 0, 64, 64, 1.f);
	Radar->AddComponent<SpriteComponent>("Radar", 8, 100, false, true, 2);
	Radar->SetZOrder(10);

	EntitiesManager->ListAllEntities();

	auto Transform = Tank1->GetComponent<TransformComponent>();
	if (Transform)
	{
		std::cout << Transform->Height;
	}
}

void GameInstance::Update()
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

	EntitiesManager->Update(DeltaTime);
}

void GameInstance::Render()
{
	// Set color and clear all canvas with it (re-draw background)
	SDL_SetRenderDrawColor(Renderer.get(), 21, 21, 21, 255);
	SDL_RenderClear(Renderer.get());
	// Render all entities on the level
	if (!EntitiesManager->HasNoEntities())
	{
		EntitiesManager->Render();
	}
	// Swap render buffers
	SDL_RenderPresent(Renderer.get());
}

void GameInstance::ProcessInput()
{
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

void GameInstance::Destroy()
{
	SDL_Quit();
}
