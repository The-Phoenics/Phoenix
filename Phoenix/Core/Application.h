#pragma once
#include <iostream>

class Application {
public:
    Application();
    virtual ~Application();
    Application(const Application&) = delete;
    Application operator=(const Application&) = delete;

    virtual void Run()
    {
        std::cout << "Hello from Phoenix";
    }

private:

};

