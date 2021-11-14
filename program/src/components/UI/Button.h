#pragma once

#include "Engine.h"

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

        void Draw() override;
        void Update() override;
        void PollEvents();
    };
}
