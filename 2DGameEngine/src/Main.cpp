#include <iostream>
#include "Core/Constants.h"
#include "Game.h"
/**
 * Entry point with the main @link Game @endlink loop 
 */
int main(int argc, char *argv[])
{
    Game *game = new Game();
    game->Initialize(WINDOW_WIDTH, WINDOW_HEIGHT);

    while (game->IsRunning())
    {
        game->ProcessInput();
        game->Update();
        game->Render();
    }

    game->Destroy();

    return 0;
}
