#pragma once

#include <SFML/Graphics.hpp>

#include "Engine/Globals.h"

namespace eke
{
    class Animation
    {
    public:
        sf::IntRect textureRect;

    private:
        sf::Vector2u imgCount;
        sf::Vector2u currImg;
        float totalTime;
        float switchTime;

    public:
        Animation(sf::Texture *texture, const sf::Vector2u imgCount, float switchTime);
        ~Animation();
        void Update(const int &row, const float &deltatime);
    };

    Animation::Animation(sf::Texture *texture, const sf::Vector2u imgCount, float switchTime)
    {
        this->imgCount = imgCount;
        this->switchTime = switchTime;
        this->totalTime = 0.f;
        this->currImg.x = 0;

        this->textureRect.width = texture->getSize().x / float(imgCount.x);
        this->textureRect.height = texture->getSize().y / float(imgCount.y);
    }

    Animation::~Animation()
    {
    }

    void Animation::Update(const int &row, const float &deltatime)
    {
        this->currImg.y = row;
        this->totalTime += deltatime;
        if (this->totalTime >= this->switchTime)
        {
            this->totalTime -= this->switchTime;
            currImg.x++;
            if (this->currImg.x >= this->imgCount.x)
            {
                this->currImg.x = 0;
            }
        }
        this->textureRect.left = this->currImg.x * this->textureRect.width;
        this->textureRect.top = this->currImg.y * this->textureRect.height;
    }

}