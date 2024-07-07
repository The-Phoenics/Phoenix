#include "Phoenix.hpp"
#include "Sandbox.h"

#include "Game.h"

Sandbox::Sandbox()
{ 
}

Sandbox::~Sandbox()
{
}

void Sandbox::Run()
{
    std::cout << "Hello from sandbox\n";
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

// sandbox will be used by engine via this function
Application* CreateApplication()
{
    return new Sandbox();
}