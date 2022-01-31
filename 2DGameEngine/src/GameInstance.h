#ifndef GAMEINSTANCE_H
#define GAMEINSTANCE_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <memory>
#include <functional>

class CameraManager;
class EntityManager;
class AssetManager;
/**
 * The main GameInstance's class contains SDL_Renderer, @link EntityManager @endlink,
 * @link AssetManager @endlink, and provides core functionality:
 * LoadLevel(), Update(), Render() and ProcessInput() methods.
 */
class GameInstance
{
public:
	GameInstance();
	~GameInstance();

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
	static std::shared_ptr<EntityManager> EntitiesManager;
	static std::shared_ptr<AssetManager> AssetsManager;
	static std::shared_ptr<CameraManager> CamerasManager;
	static 	SDL_Event event;

private:
	std::unique_ptr<SDL_Window, std::function<void(SDL_Window*)>> Window;

	bool bIsRunning;
	int TicksLastFrame;
};

#endif 