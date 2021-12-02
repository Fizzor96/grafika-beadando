#ifndef TIMER_HPP
#define TIMER_HPP 1

#include "Objects/Crosshair.h"
#include "Views/MainScene.h"
#include <SFML/Graphics.hpp>

namespace eke
{
    class Crosshair;
    class MainScene;
    // class Crosshair;
    class Timer
    {
    private:
        float originaltimer;
        bool expired;
        bool started;
        bool repeatonexpire;
        void (*expiredcallback)();
        void (*startcallback)();
        // do not invoke delete on crosshairptr!!!
        eke::Crosshair *crosshairptr;
        eke::MainScene *mainscene;
        eke::MainScene *generator;
        eke::MainScene *scored;

    private:
        void
        InitCallbackPtrs();

    public:
        float timer;
        Timer(const float &timer);
        Timer(const float &timer, const bool &repeatonexpire);
        ~Timer();
        void Update(const float &delta);
        void Start();
        void Stop();
        void Restart();
        void SetStartCallback(void (*startcallback)());
        void SetExpiredCallback(void (*expiredcallback)());
        void SetExiredCallback(eke::Crosshair *obj);
        void SetMainSceneRestartBtnExpiredCallback(eke::MainScene *obj);
        void SetMainSceneGeneratorExpiredCallback(eke::MainScene *obj);
        void MainSceneCallback();
        float GetRemainingTime();
        float GetElapsedTime();
    };
}

#endif