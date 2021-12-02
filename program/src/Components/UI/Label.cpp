#include "Label.h"

namespace eke
{
    Label::Label(const char *str, const float &posx, const float &posy)
    {
        this->text.setFont(eke::Globals::GameFont);
        this->text.setStyle(1);
        this->text.setFillColor(sf::Color::White);
        this->text.setString(str);
        sf::FloatRect bbox = this->text.getLocalBounds();
        this->text.setOrigin(sf::Vector2f(bbox.width / 2, bbox.height * 1.5));
        this->text.setPosition(sf::Vector2f(posx, posy));
    }

    Label::Label(const char *str, const sf::Vector2f position)
    {
        this->text.setFont(eke::Globals::GameFont);
        this->text.setStyle(1);
        this->text.setFillColor(sf::Color::White);
        this->text.setString(str);
        sf::FloatRect bbox = this->text.getLocalBounds();
        this->text.setOrigin(sf::Vector2f(bbox.width / 2, bbox.height * 1.5));
        this->text.setPosition(position);
    }

    Label::Label(const char *str, const float &posx, const float &posy, const sf::Color &textcolor)
    {
        this->text.setFont(eke::Globals::GameFont);
        this->text.setStyle(1);
        this->text.setFillColor(textcolor);
        this->text.setString(str);
        sf::FloatRect bbox = this->text.getLocalBounds();
        this->text.setOrigin(sf::Vector2f(bbox.width / 2, bbox.height * 1.5));
        this->text.setPosition(sf::Vector2f(posx, posy));
    }

    Label::Label(const char *str, const sf::Vector2f &position, const sf::Color &textcolor)
    {
        this->text.setFont(eke::Globals::GameFont);
        this->text.setStyle(1);
        this->text.setFillColor(textcolor);
        this->text.setString(str);
        sf::FloatRect bbox = this->text.getLocalBounds();
        this->text.setOrigin(sf::Vector2f(bbox.width / 2, bbox.height * 1.5));
        this->text.setPosition(position);
    }

    Label::~Label()
    {
    }

    void Label::Draw()
    {
        eke::Globals::RenderWindow->draw(this->text);
    }

    void Label::SetPosition(const float &posx, const float &posy)
    {
        this->text.setPosition(sf::Vector2f(posx, posy));
    }

    void Label::SetPosition(const sf::Vector2f &position)
    {
        this->text.setPosition(position);
    }

    void Label::SetColor(const sf::Color &color)
    {
        this->text.setFillColor(color);
    }

    void Label::SetText(const char *str)
    {
        this->text.setString(str);
    }
}