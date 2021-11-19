#ifndef GLOBALS_HPP
#define GLOBALS_HPP 1

#include <SFML/Graphics.hpp>
#include "Core/Timer.h"

#include <iostream>
#include <time.h>
#include <random>

namespace eke
{
    class Globals
    {
    public:
        static void Init();
        static void CleaUp();
        static void Update();
        static void PollEvents();

    public:
        // Helper to create dummy texture
        static sf::Texture CreateDummyTexture(const unsigned int &width, const unsigned int &height, const sf::Color &color);

    public:
        // Init state
        static sf::ContextSettings *CurrentContextSettings;
        static sf::RenderWindow *RenderWindow;
        static sf::Event *Event;
        static sf::Clock *Clock;
        static sf::Font GameFont;
        // Update state
        static float FPS;
        static float DeltaTime;
        static sf::Vector2f MousePosition;

    private:
        static eke::Timer *fpstimer;
        static void FpsTimerCallback();
        static void UpdateMousePos();

    public:
        Globals() = delete;
        Globals(const Globals &other) = delete;
        Globals(Globals &&other) = delete;
        ~Globals() = delete;
    };
}
#endif