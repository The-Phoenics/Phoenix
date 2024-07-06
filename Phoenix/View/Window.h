#pragma once
#include <SFML/Graphics.hpp>

class Window {
public:
    Window(const std::string &title, int width, int height);
    ~Window() = default;
    Window(const Window &) = delete;
    Window& operator=(const Window&) = delete;
    sf::RenderWindow& get() { return this->m_window; };

    void draw(sf::Sprite& sprite);
    void draw(sf::RectangleShape& sprite);
    void draw(sf::CircleShape& sprite);
    void render(const std::initializer_list<sf::Drawable*> drawableList);

private:
    sf::RenderWindow m_window;
};
