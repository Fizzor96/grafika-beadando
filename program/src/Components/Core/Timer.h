#ifndef TIMER_HPP
#define TIMER_HPP 1

#include "Objects/Crosshair.h"
#include <SFML/Graphics.hpp>

namespace eke
{
    class Crosshair;
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

    private:
        void InitCallbackPtrs();

    public:
        float timer;
        Timer(const float &timer);
        Timer(const float &timer, const bool &repeatonexpire);
        ~Timer();
        void Update(const float &delta);
        void Start();
        void Restart();
        void SetStartCallback(void (*startcallback)());
        void SetExpiredCallback(void (*expiredcallback)());
        void SetExiredCallback(eke::Crosshair *obj);
        float GetRemainingTime();
        float GetElapsedTime();
    };
}

#endif