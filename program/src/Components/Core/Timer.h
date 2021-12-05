#ifndef TIMER_HPP
#define TIMER_HPP 1

#include "Objects/Crosshair.h"
#include "Views/MainScene.h"
#include <SFML/Graphics.hpp>
#include <functional>

namespace eke
{
    class Crosshair;
    class MainScene;
    class Timer
    {
    private:
        float originaltimer;
        bool expired;
        bool started;
        bool repeatonexpire;
        std::function<void()> *startcallback;
        std::function<void()> *expiredcallback;

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
        void SetStartCallback(std::function<void()> *callbackstart);
        void SetExpiredCallback(std::function<void()> *callbackexpired);
        float GetRemainingTime();
        float GetElapsedTime();
    };
}

#endif