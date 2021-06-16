#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <memory>
#include <functional>

class EntityManager;
class AssetManager;

class Game
{
public:
	Game();
	~Game();

	bool IsRunning() const;
	
	void Initialize(int width, int height);
	void LoadLevel(unsigned int LevelNumber);
	//
	void Update();
	void Render();
	void ProcessInput();
	//
	void Destroy();

	std::shared_ptr<EntityManager> Manager;
	//
	static std::unique_ptr<SDL_Renderer, std::function<void(SDL_Renderer*)>> Renderer;
	static std::unique_ptr<AssetManager> AssetsManager;

private:
	bool bIsRunning = false;
	std::unique_ptr<SDL_Window, std::function<void(SDL_Window*)>> Window;
	int TicksLastFrame = 0;
};

#endif 