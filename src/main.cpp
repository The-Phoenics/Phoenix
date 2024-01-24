#include <SFML/Graphics.hpp>

#include "Game/Game.h"
#include "Utils/Debug.h"

int main()
{
    Logger::init();
    LOG_INFO(info msg);
    LOG_WARN(warn msg);
    LOG_ERROR(error msg);

    Game game;
    game.run();
    return 0;
}