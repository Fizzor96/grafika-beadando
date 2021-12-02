#ifndef BUTTON_HPP
#define BUTTON_HPP 1

#include "Core/Entity.h"
#include "Core/Globals.h"
#include <SFML/Graphics.hpp>
#include <functional>

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
        // void (*onclickeventcallback)();
        // void (*callback)(void *);
        // void *callbackarg;
        std::function<void()> *callback;
        void Hover();
        void Press();
        void ValidateTextLength();
        void UpdateTextures();
        void InitNullCallbacks();

    public:
        // Ctor with predifined texture (from assets)
        Button(const char *label);

        // Ctor with dummytexture
        Button(const char *label, const sf::Color &btncolor);

        // Ctors with explicit texturepaths
        Button(const char *label, const char *texturepath, const char *hovertexturepath, const char *pressedtexturepath);

        ~Button();

    public:
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

        // void SetOnClickEvent(void (*clickeventcallback)());
        // void SetOnClickEvent(void (*clickeventcallback)(void *), void *arg);
        void SetOnClickEvent(std::function<void()> &callback);

        void PollEvents() override;
        void Update() override;
        void Draw() override;

        Button() = delete;
        Button(const Button &other) = delete;
        Button(Button &&other) = delete;
        Button &operator=(const Button &other) = delete;
        Button &operator=(Button &&other) = delete;
    };
}

#endif