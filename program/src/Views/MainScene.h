#ifndef MAINSCENE_HPP
#define MAINSCENE_HPP 1

#include "Controller.h"
#include "Core.h"
#include "UI/Label.h"
#include <functional>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <vector>

namespace eke
{
    enum class SceneId;
    class Timer;

    class MainScene : public Scene
    {
    public:
        std::vector<eke::Entity *> entities;
        std::vector<eke::Entity *> buttons;
        std::vector<sf::RectangleShape *> rectangles;
        eke::Crosshair *cr;
        eke::Timer *gametimer;
        eke::Timer *generatetimer;
        eke::Label *timerlbl;
        eke::Label *scorelbl;
        int score;
        bool isplaying;

        MainScene();
        ~MainScene();

        void GenEntities();
        eke::SceneId GetSceneId() const;
        void PollEvents();
        void Update();
        void Draw();

    private:
        static eke::MainScene *Instance;

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