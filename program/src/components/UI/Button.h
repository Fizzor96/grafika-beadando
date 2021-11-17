#pragma once

#include "Core.h"

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
        Button(const Button &other) = delete;

        // If u are using default ctor, u have to set everything manually!!!
        Button();

        // Ctor with predifined texture (from assets)
        Button(const char *label);

        // Ctor with dummytexture
        Button(const char *label, const sf::Color &btncolor);

        // Ctors with explicit texturepaths
        Button(const char *label, const char *texturepath, const char *hovertexturepath, const char *pressedtexturepath);

        ~Button();

        void SetPosition(const sf::Vector2f &pos);
        sf::Vector2f GetPosition() const;

        sf::Vector2f GetSize() const;

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

        void PollEvents() override;
        void Update() override;
        void Draw() override;
    };
}
