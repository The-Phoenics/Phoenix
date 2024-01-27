#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game/Game.h"
#include "Utils/Debug.h"

int main()
{
    try
    {
        Game game;
        game.run();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}