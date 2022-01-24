#include <iostream>
#include "Core/Constants.h"
#include "GameInstance.h"
/**
 * Entry point with the main @link GameInstance @endlink loop 
 */
int main(int argc, char *argv[])
{
    GameInstance* MyGameInstance = new GameInstance();
    MyGameInstance->Initialize(WINDOW_WIDTH, WINDOW_HEIGHT);

    while (MyGameInstance->IsRunning())
    {
        MyGameInstance->ProcessInput();
        MyGameInstance->Update();
        MyGameInstance->Render();
    }

    MyGameInstance->Destroy();

    return 0;
}
