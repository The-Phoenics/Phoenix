#include <SFML/Graphics.hpp>

#include "Game/Game.h"
#include "Utils/Debug.h"

int main()
{
#ifdef DEBUG
    Logger::Init();
#endif

    Game game;
    game.run();
}