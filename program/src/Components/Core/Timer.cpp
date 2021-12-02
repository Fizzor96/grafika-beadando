#include "Core/Timer.h"

namespace eke
{
    void Timer::InitCallbackPtrs()
    {
        this->expiredcallback = nullptr;
        this->startcallback = nullptr;
        this->crosshairptr = nullptr;
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

    void Timer::SetStartCallback(void (*startcallback)())
    {
        this->startcallback = startcallback;
    }

    void Timer::SetExpiredCallback(void (*expiredcallback)())
    {
        this->expiredcallback = expiredcallback;
    }

    void Timer::SetExiredCallback(eke::Crosshair *obj)
    {
        this->crosshairptr = obj;
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
        eke::Timer::Start();
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
                if (this->crosshairptr != nullptr)
                {
                    if (this->crosshairptr->posindicator == this->crosshairptr->track.size() - 1)
                    {
                        this->crosshairptr->posindicator = 0;
                    }
                    this->crosshairptr->posindicator++;
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