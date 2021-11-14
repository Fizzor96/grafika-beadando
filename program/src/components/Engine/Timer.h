#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Engine/Globals.h"

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

    Timer::Timer(const float &timer)
    {
        this->originaltimer = timer;
        this->timer = timer;
        this->expired = false;
        this->started = false;
        this->repeatonexpire = false;
        this->expiredcallback = nullptr;
        this->startcallback = nullptr;
    }

    Timer::Timer(const float &timer, const bool &repeatonexpire)
    {
        this->originaltimer = timer;
        this->timer = timer;
        this->expired = false;
        this->started = false;
        this->repeatonexpire = repeatonexpire;
        this->expiredcallback = nullptr;
        this->startcallback = nullptr;
    }

    void Timer::SetStartCallback(void (*startcallback)())
    {
        this->startcallback = startcallback;
    }

    void Timer::SetExpiredCallback(void (*expiredcallback)())
    {
        this->expiredcallback = expiredcallback;
    }

    // Starts the timer if it is not started yet
    void Timer::Start()
    {
        if (this->started == false)
        {
            this->started = true;
            if (this->startcallback != nullptr)
            {
                this->startcallback();
            }
        }
    }

    void Timer::Restart()
    {
        this->timer = this->originaltimer;
        this->expired = false;
        this->started = false;
        Timer::Start();
    }

    void Timer::Update(const float &delta)
    {
        if (this->started == true)
        {
            timer -= delta;
            // std::cout << (int)this->timer << std::endl;
            if (this->timer <= 0)
            {
                this->started = false;
                this->expired = true;
                if (this->expiredcallback != nullptr)
                {
                    this->expiredcallback();
                }
                if (this->repeatonexpire)
                {
                    this->Restart();
                }
            }
        }
    }

    float Timer::GetRemainingTime()
    {
        return this->timer;
    }
    float Timer::GetElapsedTime()
    {
        return this->originaltimer - this->timer;
    }

    Timer::~Timer()
    {
    }

}