#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

class Game
{
public:
	Game();
	~Game();

	bool IsRunning() const;
	
	void Initialize(int width, int height);
	//
	void ProcessInput();
	void Update();
	void Render();
	//
	void Destroy();

	static SDL_Renderer* Renderer;

private:
	bool bIsRunning = false;
	SDL_Window* Window = nullptr;
	int TicksLastFrame = 0;
};

#endif 