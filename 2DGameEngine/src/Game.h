#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <memory>
#include <functional>

class EntityManager;
class AssetManager;
/**
 * The main game's class contains SDL_Renderer, @link EntityManager @endlink,
 * @link AssetManager @endlink, and provides core functionality:
 * LoadLevel(), Update(), Render() and ProcessInput() methods.
 */
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

	//
	static std::unique_ptr<SDL_Renderer, std::function<void(SDL_Renderer*)>> Renderer;
	static std::unique_ptr<EntityManager> EntitiesManager;
	static std::unique_ptr<AssetManager> AssetsManager;
	static 	SDL_Event event;

private:
	bool bIsRunning;
	std::unique_ptr<SDL_Window, std::function<void(SDL_Window*)>> Window;
	int TicksLastFrame;
};

#endif 