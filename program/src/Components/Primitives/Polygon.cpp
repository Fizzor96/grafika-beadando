#include "Polygon.h"

namespace eke
{
    Polygon::Polygon(const std::vector<sf::Vector2f> &points, const sf::Color &color, bool closed)
    {
        outlinecolor = color;
        for (size_t i = 0; i < points.size() - 1; i++)
        {
            this->linearr.push_back(new eke::Line(points[i], color, points[i + 1], color));
        }
        if (closed)
        {
            this->linearr.push_back(new eke::Line(this->linearr[this->linearr.size() - 1]->GetEndPos(), this->linearr[this->linearr.size() - 1]->GetEndColor(), this->linearr[0]->GetBeginPos(), this->linearr[0]->GetBeginColor()));
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
                this->linearr.push_back(new eke::Line(points[i], colors[i], points[i + 1], colors[i + 1]));
            }
            if (closed)
            {
                this->linearr.push_back(new eke::Line(this->linearr[this->linearr.size() - 1]->GetEndPos(), this->linearr[this->linearr.size() - 1]->GetEndColor(), this->linearr[0]->GetBeginPos(), this->linearr[0]->GetBeginColor()));
            }
            this->InitInitialImgVals();
            this->CreateEntity(colors[0]);
        }
        else if (points.size() % 2 == 0 && (points.size() / 2) == colors.size())
        {
            size_t j = 0;
            for (size_t i = 0; i < points.size(); i++)
            {
                this->linearr.push_back(new eke::Line(points[i], colors[j], points[i + 1], colors[j]));
                if (j < colors.size())
                {
                    j++;
                }
            }
            if (closed)
            {
                this->linearr.push_back(new eke::Line(this->linearr[this->linearr.size() - 1]->GetEndPos(), this->linearr[this->linearr.size() - 1]->GetEndColor(), this->linearr[0]->GetBeginPos(), this->linearr[0]->GetBeginColor()));
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
        this->minx = this->linearr[0]->positions[0].x;
        this->miny = this->linearr[0]->positions[0].y;
        this->maxx = this->linearr[0]->positions[0].x;
        this->maxy = this->linearr[0]->positions[0].y;

        // printf("%i - %i - %i - %i\n", minx, miny, maxx, maxy);
        // printf("%i\n", this->linearr[0]->positions.size());

        for (size_t i = 0; i < this->linearr.size(); i++)
        {
            for (size_t j = 0; j < this->linearr[i]->positions.size(); j++)
            {
                if (this->linearr[i]->positions[j].x < this->minx)
                {
                    this->minx = this->linearr[i]->positions[j].x;
                }
                if (this->linearr[i]->positions[j].x > this->maxx)
                {
                    this->maxx = this->linearr[i]->positions[j].x;
                }
                if (this->linearr[i]->positions[j].y < this->miny)
                {
                    this->miny = this->linearr[i]->positions[j].y;
                }
                if (this->linearr[i]->positions[j].y > this->maxy)
                {
                    this->maxy = this->linearr[i]->positions[j].y;
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
        for (size_t i = 0; i < this->linearr.size(); i++)
        {
            for (size_t j = 0; j < this->linearr[i]->positions.size(); j++)
            {
                img.setPixel(this->linearr[i]->positions[j].x - this->minx, this->linearr[i]->positions[j].y - this->miny, color);
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
            for (size_t i = 0; i < this->linearr.size(); i++)
            {
                this->linearr[i]->Move(diff.x, diff.y);
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
            for (size_t i = 0; i < this->linearr.size(); i++)
            {
                this->linearr[i]->Move(diff.x, diff.y);
            }
            // std::cout << this->linearr[0]->vertexarr[0]->GetPosition().x << " " << this->linearr[0]->vertexarr[0]->GetPosition().y << std::endl;
            this->center.x = posx;
            this->center.y = posy;
        }
    }

    void Polygon::Fill2(const sf::Color &color)
    {
        // if (bmp.GetPixel(p.X, p.Y).IsTheSameAs(background))
        //     {
        //         bmp.SetPixel(p.X, p.Y, fillcolor);
        //         bmp.FillRec4(background, fillcolor, new Point(p.X + 1, p.Y));
        //         bmp.FillRec4(background, fillcolor, new Point(p.X - 1, p.Y));
        //         bmp.FillRec4(background, fillcolor, new Point(p.X, p.Y + 1));
        //         bmp.FillRec4(background, fillcolor, new Point(p.X, p.Y - 1));
        //     }

        sf::Image img = this->sprite->getTexture()->copyToImage();
        for (size_t i = 0; i < img.getSize().y; i++)
        {
            for (size_t j = 0; j < img.getSize().x; j++)
            {
                img.setPixel(i, j, sf::Color::Magenta);
            }
        }
        img.setPixel(50, 50, sf::Color::Yellow);
        delete this->texture;
        this->texture = new sf::Texture();
        this->texture->loadFromImage(img);
        this->sprite->setTexture(*this->texture);

        // for (size_t i = 0; i < this->sprite->getTextureRect().width; i++)
        // {
        //     for (size_t j = 0; j < this->sprite->getTextureRect().height; j++)
        //     {
        //         this->sprite->getTexture()->copyToImage().setPixel();
        //     }
        // }
    }

    void Polygon::Fill(const sf::Color &color)
    {
        sf::Image img = this->sprite->getTexture()->copyToImage();
        // img.saveToFile("WTF.png");

        // std::cout << img.getSize().x << " " << img.getSize().y << std::endl;

        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};

        std::vector<sf::Vector2f> stack;

        stack.push_back(sf::Vector2f(img.getSize().x / 2, img.getSize().y / 2));

        sf::Vector2f p0, p1;

        while (stack.size() > 0)
        {
            p0 = stack[stack.size() - 1];
            stack.pop_back();

            if (!(p0.x < 0 || p0.x > img.getSize().x || p0.y > img.getSize().y || p0.y < 0))
            {
                img.setPixel(p0.x, p0.y, color);
            }

            printf("POG\n");

            for (size_t i = 0; i < 4; i++)
            {
                p1 = sf::Vector2f(p0.x + dx[i], p0.y + dy[i]);

                if (!(p1.x < 0 || p1.x > img.getSize().x || p1.y > img.getSize().y || p1.y < 0))
                {
                    if (img.getPixel(p1.x, p1.y) != color)
                    {
                        stack.push_back(p1);
                    }
                }
            }
        }
        delete this->texture;
        this->texture = new sf::Texture();
        this->texture->loadFromImage(img);
        this->sprite->setTexture(*this->texture);
    }

    sf::Vector2f Polygon::GetPosition() const
    {
        return this->sprite->getPosition();
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
        // for (size_t i = 0; i < this->linearr.size(); i++)
        // {
        //     this->linearr[i]->Draw();
        // }
        if (this->sprite != nullptr)
        {
            eke::Globals::RenderWindow->draw(*this->sprite);
        }
    }

    Polygon::~Polygon()
    {
        for (size_t i = 0; i < this->linearr.size(); i++)
        {
            delete this->linearr[i];
        }
    }
}