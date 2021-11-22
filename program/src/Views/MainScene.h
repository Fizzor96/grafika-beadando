#ifndef MAINSCENE_HPP
#define MAINSCENE_HPP 1

#include "Core.h"
#include "Controller.h"

#include <vector>

namespace eke
{
    enum class SceneId;

    class MainScene : public Scene
    {
    public:
        MainScene();
        ~MainScene();

        eke::SceneId GetSceneId() const;
        void PollEvents();
        void Update();
        void Draw();

    private:
        static eke::MainScene *Instance;
        std::vector<eke::Entity *> entities;
        std::vector<eke::Polygon *> drawables;
        std::vector<sf::RectangleShape *> rectangles;
        eke::Crosshair *cr;

    private:
        void InitComponents();

    public:
        MainScene(const MainScene &other) = delete;
        MainScene(MainScene &&other) = delete;
        MainScene &operator=(const MainScene &other) = delete;
        MainScene &operator=(MainScene &&other) = delete;
    };
}

#endif