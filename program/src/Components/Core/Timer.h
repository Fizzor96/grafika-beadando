#ifndef TIMER_HPP
#define TIMER_HPP 1

#include <SFML/Graphics.hpp>

namespace eke
{
    class Timer
    {
    private:
        float timer;
        float originaltimer;
        bool expired;
        bool started;
        bool repeatonexpire;
        void (*expiredcallback)();
        void (*startcallback)();

    public:
        Timer(const float &timer);
        Timer(const float &timer, const bool &repeatonexpire);
        ~Timer();
        void Update(const float &delta);
        void Start();
        void Restart();
        void SetStartCallback(void (*startcallback)());
        void SetExpiredCallback(void (*expiredcallback)());
        bool GetState();
        float GetRemainingTime();
        float GetElapsedTime();
    };
}

#endif