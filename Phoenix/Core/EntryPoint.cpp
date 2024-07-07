#include "Core/Application.h"

extern Application* CreateApplication();

int main()
{
    // try
    // {
    //     Game game;
    //     game.run();
    // }
    // catch (const std::exception &e)
    // {
    //     std::cerr << e.what() << '\n';
    // }

    auto app = CreateApplication();
    app->Run();
}