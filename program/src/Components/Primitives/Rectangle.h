#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP 1

#include "Core/Entity.h"
#include "Line.h"
#include <SFML/Graphics.hpp>
#include <vector>

namespace eke
{
    class Rectangle : public Entity
    {
    private:
        sf::Vector2f position;
        sf::FloatRect boundingbox;

    public:
        Rectangle(const sf::Vector2f &size, const sf::Vector2f &centerpos, const sf::Color &color);
        Rectangle(const float &width, const float &height, const float &centerx, const float &centery, const sf::Color &color);
        void SetPosition(const float &posx, const float &posy);
        void SetPosition(const sf::Vector2f &pos);
        sf::FloatRect GetGlobalBounds() const override;
        sf::Vector2f GetPosition() const;
        sf::Vector2f GetSize() const;
        void PollEvents() override;
        void Update() override;
        void Draw() override;
        ~Rectangle();

        Rectangle() = delete;
        Rectangle(const Rectangle &other) = delete;
        Rectangle(Rectangle &&other) = delete;
        Rectangle &operator=(const Rectangle &other) = delete;
        Rectangle &operator=(Rectangle &&other) = delete;
    };
}

#endif