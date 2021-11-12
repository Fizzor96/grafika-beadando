#pragma once

#include <string>
#include <iostream>

#include <SFML/Graphics.hpp>

#include "Game.h"

// TODO: GameMyText Implementation

class MyText
{
public:
    static void Init();
    MyText();
    MyText(const std::string &str);
    MyText(const char *str);
    MyText(const std::string &str, const sf::Vector2f &pos);
    ~MyText();

    void SetText(const char *str);
    void SetText(const std::string &str);
    void Update();
    sf::Text &GetDrawable() { return this->txt; }

    void SetPosition(const sf::Vector2f &newpos);
    const sf::Vector2f &GetPosition() { return txt.getPosition(); }

private:
    sf::Text txt;
    sf::Font font;
    static sf::Font Font;

public:
    MyText(const MyText &other) = delete;
    MyText(MyText &&other) = delete;
};