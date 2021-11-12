#include "MyText.h"
#include "Game.h"

#define FONTPATH1 "arial.ttf"
#define FONTPATH2 "../arial.ttf"

#define FONTPATH3 "monogram.ttf"
#define FONTPATH4 "../monogram.ttf"

sf::Font MyText::Font;

void MyText::Init()
{
    if (!MyText::Font.loadFromFile(FONTPATH3))
    {
        std::cerr << "Error Loading Font: FONTPATH1!\n";
        if (!MyText::Font.loadFromFile(FONTPATH4))
        {
            std::cerr << "Error Loading Font: FONTPATH2!\n";
        }
        else
        {
            std::cout << "Loaded Font: FONTPATH2\n";
        }
    }
    else
    {
        std::cout << "Loaded Font: FONTPATH1\n";
    }
}

MyText::MyText()
{
    // a
}

MyText::MyText(const std::string &str)
{
    txt.setFont(MyText::Font);
    txt.setString(str);
}

MyText::MyText(const char *str)
{
    txt.setFont(MyText::Font);
    txt.setString(static_cast<std::string>(str));
}

MyText::MyText(const std::string &str, const sf::Vector2f &pos)
{
    txt.setString(str);
    txt.setFont(MyText::Font);
    txt.setFillColor(sf::Color::White);
    txt.setPosition(pos);
}

MyText::~MyText()
{
    // a
}

void MyText::SetText(const char *str)
{
    txt.setString(static_cast<std::string>(str));
}

void MyText::SetText(const std::string &str)
{
    txt.setString(str);
}

void MyText::SetPosition(const sf::Vector2f &newpos)
{
    txt.setPosition(newpos);
}