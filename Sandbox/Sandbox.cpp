#include "Phoenix.hpp"
#include "Sandbox.h"

Sandbox::Sandbox()
{ 
}

Sandbox::~Sandbox()
{
}

// sandbox will be used by engine via this function
Application* CreateApplication()
{
    return new Sandbox();
}