#pragma once

#include <iostream>
#include <string>

#include "Globals.h"

#include "Entity.h"

#include "SFML/Graphics.hpp"

namespace eke
{
    class Button : public Entity
    {

    private:
        static sf::Color TextColor;
        sf::Texture *hover;
        sf::Texture *pressed;
        sf::Text label;
        sf::FloatRect lblboundingbox;
        void (*onclickeventcallback)();
        void Hover();
        void Press();
        void ValidateTextLength();
        void UpdateTextures();

    public:
        // If u are using default ctor, u have to set everything manually!!!
        Button();
        Button(const char *label, const sf::Vector2f &pos);
        Button(const char *label, const sf::Vector2f &pos, const sf::Color &btncolor);
        // Button(const sf::Vector2f pos, const char *labeltexturepath);
        Button(const char *label, const sf::Vector2f &pos, const char *texturepath);
        Button(const char *label, const sf::Vector2f &pos, const char *texturepath, const char *hovertexturepath);
        Button(const char *label, const sf::Vector2f &pos, const char *texturepath, const char *hovertexturepath, const char *pressedtexturepath);
        ~Button();

        void SetPosition(const sf::Vector2f &pos);

        void SetText(const char *str);
        void SetText(const std::string &str);

        void SetTextColor(const sf::Color &color);
        void SetTextColor(const unsigned char &red, const unsigned char &green, const unsigned char &blue, const unsigned char &alpha = 255);

        void SetButtonColor(const sf::Color &color);
        void SetButtonColor(const unsigned char &red, const unsigned char &green, const unsigned char &blue, const unsigned char &alpha = 255);

        void SetTexture(const char *texturepath);
        void SetHoverTexture(const char *hovertexturepath);
        void SetPressedTexture(const char *pressedtexturepath);

        void SetOnClickEvent(void (*clickeventcallback)());

        void Draw();
        void Update();
        void PollEvents();
    };

    // Default color of the label shown in the button
    sf::Color Button::TextColor = sf::Color::White;

    void Button::ValidateTextLength()
    {
        if (this->lblboundingbox.width > this->sprite->getTextureRect().width)
        {
            float tempx = (this->lblboundingbox.width / this->sprite->getTextureRect().width) * 1.2;
            this->sprite->setScale(sf::Vector2f(tempx, this->sprite->getScale().y));
            this->label.setPosition(this->sprite->getPosition());
        }
        if (this->lblboundingbox.height > this->sprite->getTextureRect().height)
        {
            float tempy = this->lblboundingbox.height * 3;
            this->sprite->setScale(sf::Vector2f(this->sprite->getScale().x, tempy));
            this->label.setPosition(this->sprite->getPosition());
        }
    }

    void Button::UpdateTextures()
    {
        if (this->sprite->getGlobalBounds().contains(eke::Globals::MousePosition))
        {
            if (eke::Globals::Event->type == sf::Event::MouseButtonPressed && eke::Globals::Event->mouseButton.button == sf::Mouse::Left)
            {
                this->sprite->setTexture(*this->pressed);
            }
            else
            {
                this->sprite->setTexture(*this->hover);
            }
        }
        else
        {
            this->sprite->setTexture(*this->texture);
        }
    }

    Button::Button()
    {
        this->sprite = new sf::Sprite();
        this->texture = nullptr;
        this->hover = nullptr;
        this->pressed = nullptr;

        this->label.setFont(eke::Globals::GameFont);
        this->label.setFillColor(Button::TextColor);
        this->label.setString("");
        this->lblboundingbox = this->label.getLocalBounds();
        this->label.setOrigin(sf::Vector2f(this->lblboundingbox.width / 2, this->lblboundingbox.height * 1.5));

        ValidateTextLength();
    }

    Button::Button(const char *label, const sf::Vector2f &pos)
    {
        this->sprite = new sf::Sprite();
        this->texture = new sf::Texture();
        this->hover = new sf::Texture();
        this->pressed = new sf::Texture();

        this->label.setFont(eke::Globals::GameFont);
        this->label.setFillColor(Button::TextColor);
        this->label.setStyle(1);
        this->label.setString(label);
        this->lblboundingbox = this->label.getLocalBounds();
        this->label.setOrigin(sf::Vector2f(this->lblboundingbox.width / 2, this->lblboundingbox.height * 1.5));

        this->texture->loadFromFile("../assets/buttons/original.png");
        this->hover->loadFromFile("../assets/buttons/hoovered.png");
        this->pressed->loadFromFile("../assets/buttons/pressed.png");

        this->sprite->setTexture(*this->texture);

        this->sprite->setTextureRect(sf::IntRect(this->sprite->getTextureRect().left, this->sprite->getTextureRect().top, this->sprite->getTextureRect().width, this->sprite->getTextureRect().height));
        this->sprite->setOrigin(sf::Vector2f(this->sprite->getTextureRect().width / 2, this->sprite->getTextureRect().height / 2));

        this->sprite->setPosition(pos);
        this->label.setPosition(this->sprite->getPosition());

        ValidateTextLength();
    }

    Button::Button(const char *label, const sf::Vector2f &pos, const sf::Color &btncolor)
    {
        this->sprite = new sf::Sprite();
        this->texture = new sf::Texture();
        this->hover = nullptr;
        this->pressed = nullptr;

        this->label.setFont(eke::Globals::GameFont);
        this->label.setString(label);
        this->lblboundingbox = this->label.getLocalBounds();
        this->label.setOrigin(sf::Vector2f(this->lblboundingbox.width / 2, this->lblboundingbox.height * 1.5));

        sf::Texture temptexture = eke::Globals::CreateDummyTexture(this->lblboundingbox.width, this->lblboundingbox.height, btncolor);

        this->sprite->setTexture(temptexture);
        this->sprite->setColor(btncolor);
        this->sprite->setTextureRect(sf::IntRect(this->sprite->getTextureRect().left, this->sprite->getTextureRect().top, this->lblboundingbox.width * 1.2, this->lblboundingbox.height * 3));
        this->sprite->setOrigin(sf::Vector2f(this->sprite->getTextureRect().width / 2, this->sprite->getTextureRect().height / 2));

        this->sprite->setPosition(pos);
        this->label.setPosition(this->sprite->getPosition());

        ValidateTextLength();
    }

    Button::Button(const char *label, const sf::Vector2f &pos, const char *texturepath)
    {
        this->sprite = new sf::Sprite();
        this->texture = new sf::Texture();
        this->hover = nullptr;
        this->pressed = nullptr;

        this->label.setFont(eke::Globals::GameFont);
        this->label.setString(label);
        this->lblboundingbox = this->label.getLocalBounds();
        this->label.setOrigin(sf::Vector2f(this->lblboundingbox.width / 2, this->lblboundingbox.height * 1.5));

        this->texture->loadFromFile(texturepath);

        this->sprite->setTexture(*this->texture);
        this->sprite->setTextureRect(sf::IntRect(this->sprite->getTextureRect().left, this->sprite->getTextureRect().top, this->sprite->getTextureRect().width, this->sprite->getTextureRect().height));
        this->sprite->setOrigin(sf::Vector2f(this->sprite->getTextureRect().width / 2, this->sprite->getTextureRect().height / 2));

        this->sprite->setPosition(pos);
        this->label.setPosition(this->sprite->getPosition());

        ValidateTextLength();
    }

    Button::Button(const char *label, const sf::Vector2f &pos, const char *texturepath, const char *hovertexturepath)
    {
        this->sprite = new sf::Sprite();
        this->texture = new sf::Texture();
        this->hover = new sf::Texture();
        this->pressed = nullptr;

        this->label.setFont(eke::Globals::GameFont);
        this->label.setString(label);
        this->lblboundingbox = this->label.getLocalBounds();
        this->label.setOrigin(sf::Vector2f(this->lblboundingbox.width / 2, this->lblboundingbox.height * 1.5));

        this->texture->loadFromFile(texturepath);
        this->hover->loadFromFile(hovertexturepath);

        this->sprite->setTexture(*this->texture);
        this->sprite->setTextureRect(sf::IntRect(this->sprite->getTextureRect().left, this->sprite->getTextureRect().top, this->sprite->getTextureRect().width, this->sprite->getTextureRect().height));
        this->sprite->setOrigin(sf::Vector2f(this->sprite->getTextureRect().width / 2, this->sprite->getTextureRect().height / 2));

        this->sprite->setPosition(pos);
        this->label.setPosition(this->sprite->getPosition());

        ValidateTextLength();
    }

    Button::Button(const char *label, const sf::Vector2f &pos, const char *texturepath, const char *hovertexturepath, const char *pressedtexturepath)
    {
        this->sprite = new sf::Sprite();
        this->texture = new sf::Texture();
        this->hover = new sf::Texture();
        this->pressed = new sf::Texture();

        this->label.setFont(eke::Globals::GameFont);
        this->label.setString(label);
        this->lblboundingbox = this->label.getLocalBounds();
        this->label.setOrigin(sf::Vector2f(this->lblboundingbox.width / 2, this->lblboundingbox.height * 1.5));

        this->texture->loadFromFile(texturepath);
        this->hover->loadFromFile(hovertexturepath);
        this->pressed->loadFromFile(pressedtexturepath);

        this->sprite->setTexture(*this->texture);

        this->sprite->setTextureRect(sf::IntRect(this->sprite->getTextureRect().left, this->sprite->getTextureRect().top, this->sprite->getTextureRect().width, this->sprite->getTextureRect().height));
        this->sprite->setOrigin(sf::Vector2f(this->sprite->getTextureRect().width / 2, this->sprite->getTextureRect().height / 2));

        this->sprite->setPosition(pos);
        this->label.setPosition(this->sprite->getPosition());

        ValidateTextLength();
    }

    Button::~Button()
    {
        delete this->sprite;
        delete this->texture;
        delete this->hover;
        delete this->pressed;
    }

    void Button::SetPosition(const sf::Vector2f &pos)
    {
        this->sprite->setPosition(pos);
        this->label.setPosition(this->sprite->getPosition());
    }

    void Button::SetText(const char *str)
    {
        this->label.setString(std::string(str));
        this->lblboundingbox = this->label.getLocalBounds();
        this->label.setOrigin(sf::Vector2f(this->lblboundingbox.width / 2, this->lblboundingbox.height * 1.5));
        this->label.setPosition(this->sprite->getPosition());
    }

    void Button::SetText(const std::string &str)
    {
        this->label.setString(str);
        this->lblboundingbox = this->label.getLocalBounds();
        this->label.setOrigin(sf::Vector2f(this->lblboundingbox.width / 2, this->lblboundingbox.height * 1.5));
        this->label.setPosition(this->sprite->getPosition());
    }

    void Button::SetTextColor(const sf::Color &color)
    {
        this->label.setFillColor(color);
    }

    void Button::SetTextColor(const unsigned char &red, const unsigned char &green, const unsigned char &blue, const unsigned char &alpha)
    {
        this->label.setFillColor(sf::Color(red, green, blue, alpha));
    }

    void Button::SetButtonColor(const sf::Color &color)
    {
        sf::Texture temptexture = eke::Globals::CreateDummyTexture(this->lblboundingbox.width, this->lblboundingbox.height, color);
        this->sprite->setTexture(temptexture);
    }

    void Button::SetButtonColor(const unsigned char &red, const unsigned char &green, const unsigned char &blue, const unsigned char &alpha)
    {
        sf::Texture temptexture = eke::Globals::CreateDummyTexture(this->lblboundingbox.width, this->lblboundingbox.height, sf::Color(red, green, blue, alpha));
        this->sprite->setTexture(temptexture);
    }

    void Button::SetTexture(const char *texturepath)
    {
        this->sprite->setColor(sf::Color::White);
        this->texture->loadFromFile(texturepath);
        this->sprite->setTexture(*this->texture);
        this->sprite->setTextureRect(sf::IntRect(this->sprite->getTextureRect().left, this->sprite->getTextureRect().top, this->texture->getSize().x, this->texture->getSize().y));
        this->sprite->setOrigin(sf::Vector2f(this->sprite->getTextureRect().width / 2, this->sprite->getTextureRect().height / 2));
        ValidateTextLength();
    }

    void Button::SetHoverTexture(const char *hovertexturepath)
    {
        this->hover = new sf::Texture();
        this->hover->loadFromFile(hovertexturepath);
    }

    void Button::SetPressedTexture(const char *pressedtexturepath)
    {
        this->pressed = new sf::Texture();
        this->pressed->loadFromFile(pressedtexturepath);
    }

    void Button::SetOnClickEvent(void (*clickeventcallback)())
    {
        this->onclickeventcallback = clickeventcallback;
    }

    void Button::Draw()
    {
        if (this->sprite != nullptr)
        {
            eke::Globals::RenderWindow->draw(*this->sprite);
            eke::Globals::RenderWindow->draw(this->label);
        }
    }

    void Button::Update()
    {
        UpdateTextures();
    }

    void Button::PollEvents()
    {
        if (this->sprite->getGlobalBounds().contains(eke::Globals::MousePosition))
        {
            if (eke::Globals::Event->type == sf::Event::MouseButtonPressed && eke::Globals::Event->mouseButton.button == sf::Mouse::Left)
            {
                this->onclickeventcallback();
            }
        }
    }
}
