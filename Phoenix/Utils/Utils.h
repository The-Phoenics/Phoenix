#pragma once
#include <random>
#include <SFML/Graphics.hpp>

inline int randomInteger(int min, int max)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::uniform_int_distribution<int> dist(min, max);
    return dist(gen);
}

inline sf::Color randomColor() {
    sf::Color color;
    color.r = randomInteger(0, 255);
    color.g = randomInteger(0, 255);
    color.b = randomInteger(0, 255);
    return color;
}