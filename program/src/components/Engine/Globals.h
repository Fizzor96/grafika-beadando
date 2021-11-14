#pragma once
#include <vector>
#include "Engine.h"

namespace eke
{
    class Globals
    {
    public:
        static void Init();
        static void Start();
        static void CleaUp();

    public:
        // Helper to create dummy texture
        static sf::Texture CreateDummyTexture(const unsigned int &width, const unsigned int &height, const sf::Color &color);

    private:
        static void PollEvents();
        static void Update();
        static void Draw();

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
        // Scenes
        // static std::vector<eke::Scene *> Scenes;

    public:
        Globals() = delete;
        Globals(const Globals &other) = delete;
        Globals(Globals &&other) = delete;
        ~Globals() = delete;
    };
}
