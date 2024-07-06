#include <SFML/Graphics.hpp>
#include "Game/Game.h"

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