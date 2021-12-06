#include "zh1.h"

namespace eke
{
    void zh1::CreateSetRect()
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && this->isgrabbed == false)
        {
            sf::Vector2f pos(rand() % 80 + 30, rand() % 80 + 30);
            sf::Color color(rand() % 255, rand() % 255, rand() % 255, 255);

            MyRect *rect = new MyRect(pos, color);

            rect->SetPosition(sf::Vector2f(eke::Globals::MousePosition.x - rect->GetSize().x, eke::Globals::MousePosition.y - rect->GetSize().y));
            this->rectvec.push_back(rect);
            this->isgrabbed = true;
        }
        if (this->isgrabbed == true && this->rectvec.size() > 0)
        {
            MyRect *temp = this->rectvec[this->rectvec.size() - 1];
            sf::Vector2f botright(sf::Vector2f(eke::Globals::MousePosition.x - temp->GetSize().x, eke::Globals::MousePosition.y - temp->GetSize().y));
            temp->SetPosition(botright);
            if (!sf::Mouse::isButtonPressed(sf::Mouse::Right))
            {
                this->isgrabbed = false;
            }
        }
    }

    void zh1::ClearRecVec()
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Middle) && this->rectvec.size() > 0)
        {
            for (size_t i = 0; i < this->rectvec.size(); i++)
            {
                delete this->rectvec[i];
            }
            this->rectvec.clear();
        }
    }

    void zh1::Update()
    {
        CreateSetRect();
        ClearRecVec();

        for (size_t i = 0; i < this->rectvec.size(); i++)
        {
            this->rectvec[i]->Update();
        }
    }

    void zh1::Draw()
    {
        for (size_t i = 0; i < this->rectvec.size(); i++)
        {
            this->rectvec[i]->Draw();
        }
    }

    zh1::zh1()
    {
        srand(time(NULL));
        this->isgrabbed = false;
    }

    zh1::~zh1()
    {
        for (size_t i = 0; i < this->rectvec.size(); i++)
        {
            delete this->rectvec[i];
        }
        this->rectvec.clear();
    }
}