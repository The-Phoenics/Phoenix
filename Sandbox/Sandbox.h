#pragma once
#include "Phoenix.hpp"
#include <iostream>

class Sandbox : public Application
{
public:
    Sandbox();
    ~Sandbox();
    Sandbox(const Sandbox&) = delete;
    Sandbox operator=(const Sandbox&) = delete;

    void Run();
};
