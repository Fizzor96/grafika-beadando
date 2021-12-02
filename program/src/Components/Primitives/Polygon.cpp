#include "Polygon.h"

namespace eke
{
    Polygon::Polygon(const std::vector<sf::Vector2f> &points, const sf::Color &color, bool closed)
    {
        outlinecolor = color;
        for (size_t i = 0; i < points.size() - 1; i++)
        {
            this->lines.push_back(new eke::Line(points[i], color, points[i + 1], color));
        }
        if (closed)
        {
            this->lines.push_back(new eke::Line(this->lines[this->lines.size() - 1]->GetEndPos(), this->lines[this->lines.size() - 1]->GetEndColor(), this->lines[0]->GetBeginPos(), this->lines[0]->GetBeginColor()));
        }
        this->InitInitialImgVals();
        this->CreateEntity(color);
    }

    Polygon::Polygon(const std::vector<sf::Vector2f> &points, const std::vector<sf::Color> &colors, bool closed)
    {
        if (points.size() == colors.size())
        {
            for (size_t i = 0; i < points.size() - 1; i++)
            {
                this->lines.push_back(new eke::Line(points[i], colors[i], points[i + 1], colors[i + 1]));
            }
            if (closed)
            {
                this->lines.push_back(new eke::Line(this->lines[this->lines.size() - 1]->GetEndPos(), this->lines[this->lines.size() - 1]->GetEndColor(), this->lines[0]->GetBeginPos(), this->lines[0]->GetBeginColor()));
            }
            this->InitInitialImgVals();
            this->CreateEntity(colors[0]);
        }
        else if (points.size() % 2 == 0 && (points.size() / 2) == colors.size())
        {
            size_t j = 0;
            for (size_t i = 0; i < points.size(); i++)
            {
                this->lines.push_back(new eke::Line(points[i], colors[j], points[i + 1], colors[j]));
                if (j < colors.size())
                {
                    j++;
                }
            }
            if (closed)
            {
                this->lines.push_back(new eke::Line(this->lines[this->lines.size() - 1]->GetEndPos(), this->lines[this->lines.size() - 1]->GetEndColor(), this->lines[0]->GetBeginPos(), this->lines[0]->GetBeginColor()));
            }
            this->InitInitialImgVals();
            this->CreateEntity(colors[0]);
        }
        else
        {
            this->sprite = nullptr;
            std::cout << "Invalid args!\n";
        }
    }

    void Polygon::InitInitialImgVals()
    {
        this->minx = this->lines[0]->positions[0].x;
        this->miny = this->lines[0]->positions[0].y;
        this->maxx = this->lines[0]->positions[0].x;
        this->maxy = this->lines[0]->positions[0].y;

        // printf("%i - %i - %i - %i\n", minx, miny, maxx, maxy);
        // printf("%i\n", this->linearr[0]->positions.size());

        for (size_t i = 0; i < this->lines.size(); i++)
        {
            for (size_t j = 0; j < this->lines[i]->positions.size(); j++)
            {
                if (this->lines[i]->positions[j].x < this->minx)
                {
                    this->minx = this->lines[i]->positions[j].x;
                }
                if (this->lines[i]->positions[j].x > this->maxx)
                {
                    this->maxx = this->lines[i]->positions[j].x;
                }
                if (this->lines[i]->positions[j].y < this->miny)
                {
                    this->miny = this->lines[i]->positions[j].y;
                }
                if (this->lines[i]->positions[j].y > this->maxy)
                {
                    this->maxy = this->lines[i]->positions[j].y;
                }
            }
        }

        this->center.x = (this->minx + this->maxx) / 2;
        this->center.y = (this->miny + this->maxy) / 2;
    }

    void Polygon::CreateEntity(const sf::Color &color)
    {
        sf::Image img;
        unsigned int extension = 1;
        img.create((this->maxx - this->minx) + extension, (this->maxy - this->miny) + extension, sf::Color(0, 0, 0, 0));
        for (size_t i = 0; i < this->lines.size(); i++)
        {
            for (size_t j = 0; j < this->lines[i]->positions.size(); j++)
            {
                img.setPixel(this->lines[i]->positions[j].x - this->minx, this->lines[i]->positions[j].y - this->miny, color);
            }
        }
        // printf("pog\n");
        this->texture = new sf::Texture();
        this->texture->loadFromImage(img);
        this->sprite = new sf::Sprite();
        this->sprite->setTexture(*this->texture);
        this->sprite->setOrigin(this->sprite->getGlobalBounds().width / 2, this->sprite->getGlobalBounds().height / 2);
    }

    void Polygon::SetPosition(const sf::Vector2f &pos)
    {
        this->sprite->setPosition(pos);

        if (this->center != pos)
        {
            sf::Vector2f diff;
            diff.x = pos.x - this->center.x;
            diff.y = pos.y - this->center.y;
            for (size_t i = 0; i < this->lines.size(); i++)
            {
                this->lines[i]->Move(diff.x, diff.y);
            }
            this->center.x = pos.x;
            this->center.y = pos.y;
        }
    }

    void Polygon::SetPosition(const float &posx, const float &posy)
    {
        this->sprite->setPosition(sf::Vector2f(posx, posy));

        if (this->center.x != posx && this->center.y != posy)
        {
            sf::Vector2f diff;
            diff.x = posx - this->center.x;
            diff.y = posy - this->center.y;
            // std::cout << diff.x << " " << diff.y << std::endl;
            // std::cout << this->linearr[0]->vertexarr[0]->GetPosition().x << " " << this->linearr[0]->vertexarr[0]->GetPosition().y << std::endl;
            for (size_t i = 0; i < this->lines.size(); i++)
            {
                this->lines[i]->Move(diff.x, diff.y);
            }
            // std::cout << this->linearr[0]->vertexarr[0]->GetPosition().x << " " << this->linearr[0]->vertexarr[0]->GetPosition().y << std::endl;
            this->center.x = posx;
            this->center.y = posy;
        }
    }

    void Polygon::Fill(const sf::Color &color)
    {
        sf::Texture temptexture(*this->sprite->getTexture());
        auto size = temptexture.getSize();
        // std::cout << size.x << " " << size.y << std::endl;
        sf::Image img = temptexture.copyToImage();

        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};

        std::vector<sf::Vector2f> stack;

        stack.push_back(sf::Vector2f((int)(size.x / 2), (int)(size.y / 2)));

        sf::Vector2f p0, p1;

        while (stack.size() > 0)
        {
            p0 = stack[stack.size() - 1];
            stack.pop_back();
            // printf("stack size: %i\n", stack.size());

            img.setPixel(p0.x, p0.y, color);
            std::cout << "p0: " << p0.x << " " << p0.y << std::endl;

            for (size_t i = 0; i < 4; i++)
            {
                p1.x = (int)(p0.x + dx[i]);
                p1.y = (int)(p0.y + dy[i]);
                std::cout << "p1: " << p1.x << " " << p1.y << std::endl;
                // p1 = sf::Vector2f(p0.x + dx[i], p0.y + dy[i]);

                std::this_thread::sleep_for(std::chrono::milliseconds(200));

                if (img.getPixel(p1.x, p1.y) != color)
                {
                    stack.push_back(p1);
                }
            }
        }
        this->texture->loadFromImage(img);
        this->sprite->setTexture(*this->texture);
    }

    void Polygon::ToString()
    {
        std::cout << "center: " << this->center.x << " " << this->center.y << " minx: " << this->minx << " maxx: " << this->maxx << " miny: " << this->miny << " maxy: " << this->maxy << std::endl;
    }

    void Polygon::PollEvents()
    {
    }

    void Polygon::Update()
    {
    }

    void Polygon::Draw()
    {
        for (size_t i = 0; i < this->lines.size(); i++)
        {
            this->lines[i]->Draw();
        }
        // if (this->sprite != nullptr)
        // {
        //     eke::Globals::RenderWindow->draw(*this->sprite);
        // }
    }

    Polygon::~Polygon()
    {
        for (size_t i = 0; i < this->lines.size(); i++)
        {
            delete this->lines[i];
        }
    }
}