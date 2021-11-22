#ifndef PIXEL_HPP
#define PIXEL_HPP 1

#include "Core/Globals.h"
#include "Core/Entity.h"

namespace eke
{
    class Pixel : public Entity
    {
    public:
        sf::Color color;

    public:
        Pixel(const sf::Vector2f &position);
        Pixel(const float &posx, const float &posy);
        Pixel(const sf::Vector2f &position, const sf::Color &color);
        Pixel(const float &posx, const float &posy, const sf::Color &color);
        ~Pixel();

        void SetScale(const sf::Vector2f &factor);

        void SetPosition(const sf::Vector2f &pos);
        void SetPosition(const float &posx, const float &posy);
        void SetColor(const sf::Color &color);
        sf::Vector2f GetPosition() const;
        sf::Color GetColor() const;

        void PollEvents() override;
        void Update() override;
        void Draw() override;

        Pixel() = delete;
        Pixel(const Pixel &other) = delete;
        Pixel(Pixel &&other) = delete;
        Pixel &operator=(const Pixel &other) = delete;
        Pixel &operator=(Pixel &&other) = delete;
    };
}

#endif