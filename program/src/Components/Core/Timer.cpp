#include "Core/Timer.h"

namespace eke
{
    void Timer::InitCallbackPtrs()
    {
        this->startcallback = nullptr;
        this->expiredcallback = nullptr;
    }

    eke::Timer::Timer(const float &timer)
    {
        this->originaltimer = timer;
        this->timer = timer;
        this->expired = false;
        this->started = false;
        this->repeatonexpire = false;
        InitCallbackPtrs();
        this->Start();
    }

    eke::Timer::Timer(const float &timer, const bool &repeatonexpire)
    {
        this->originaltimer = timer;
        this->timer = timer;
        this->expired = false;
        this->started = false;
        this->repeatonexpire = repeatonexpire;
        InitCallbackPtrs();
        // this->Start();
    }

    void Timer::SetStartCallback(std::function<void()> *cllbkstart)
    {
        this->startcallback = cllbkstart;
    }
    void Timer::SetExpiredCallback(std::function<void()> *cllbkexpired)
    {
        this->expiredcallback = cllbkexpired;
    }

    // Starts the timer if it is not started yet
    void Timer::Start()
    {
        if (this->started == false)
        {
            this->started = true;
            if (this->startcallback != nullptr)
            {
                (*this->startcallback)();
            }
        }
    }

    void Timer::Stop()
    {
        this->timer = this->originaltimer;
        this->expired = false;
        this->started = false;
    }

    void Timer::Restart()
    {
        this->timer = this->originaltimer;
        this->expired = false;
        this->started = false;
        eke::Timer::Start();
    }

    void Timer::Update(const float &delta)
    {
        if (this->started == true)
        {
            timer -= delta;
            // On expiration
            if (this->timer <= 0)
            {
                this->started = false;
                this->expired = true;
                if (this->expiredcallback != nullptr)
                {
                    (*this->expiredcallback)();
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