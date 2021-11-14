#include "Animation.h"

namespace eke
{
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