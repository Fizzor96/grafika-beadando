#ifndef LABEL_HPP
#define LABEL_HPP 1

#include "Core/Globals.h"
#include <SFML/Graphics.hpp>
#include <string>

namespace eke
{
    class Label
    {
    private:
        sf::Text text;
        sf::Color textcolor;

    public:
        Label(const char *str, const float &posx, const float &posy);
        Label(const char *str, const sf::Vector2f position);
        Label(const char *str, const float &posx, const float &posy, const sf::Color &textcolor);
        Label(const char *str, const sf::Vector2f &position, const sf::Color &textcolor);
        void SetPosition(const float &posx, const float &posy);
        void SetPosition(const sf::Vector2f &position);
        sf::Vector2f GetPosition() const;
        void SetColor(const sf::Color &color);
        void SetText(const char *str);
        void Draw();
        ~Label();

        Label() = delete;
        Label(const Label &other) = delete;
        Label(Label &&other) = delete;
        Label &operator=(const Label &other) = delete;
        Label &operator=(Label &&other) = delete;
    };
}

#endif