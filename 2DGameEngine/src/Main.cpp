#include <iostream>
#include "Core/Constants.h"
#include "GameInstance.h"
/**
 * Entry point with the main @link GameInstance @endlink loop 
 */
int main(int argc, char *argv[])
{
    auto MyGameInstance = std::make_unique<GameInstance>();
    MyGameInstance->Initialize(WINDOW_WIDTH, WINDOW_HEIGHT);

    while (MyGameInstance->IsRunning())
    {
        MyGameInstance->ProcessInput();
        MyGameInstance->Update();
        MyGameInstance->Render();
    }

    return 0;
}
