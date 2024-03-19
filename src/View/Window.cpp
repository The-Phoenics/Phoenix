#include "Window.h"

Window::Window(const std::string &title, int width, int height)
    : m_window(sf::VideoMode(width, height), title)
{
    m_window.setFramerateLimit(60);
}

void Window::draw(sf::Sprite& sprite)
{
    this->m_window.draw(sprite);
}

void Window::draw(sf::RectangleShape& sprite)
{
    this->m_window.draw(sprite);
}

void Window::render(const std::initializer_list<sf::Drawable*> drawableList)
{
    m_window.clear(sf::Color::Black);
    for (const auto& object: drawableList) {
        m_window.draw(*object);
    }
    m_window.display();
}
