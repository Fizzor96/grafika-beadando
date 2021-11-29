#ifndef ELLIPSE2_HPP
#define ELLIPSE2_HPP 1

#include <SFML/Graphics.hpp>
#include "Core/Globals.h"
#include "Primitives/Line.h"
#include "Pixel.h"
#include <math.h>
#include <vector>
#include <iostream>

namespace eke
{
    class Ellipse2
    {
    public:
        static std::vector<sf::Vector2f> GenerateEllipse2Positions(float posx, float posy, float r1, float r2);

    public:
        std::vector<eke::Pixel *> vertexarr;
        std::vector<sf::Vector2f> positions;
        sf::Vector2f position;
        float r1, r2;
        std::vector<eke::Line *> lines;

    public:
        Ellipse2(float posx, float posy, float r1, float r2);
        ~Ellipse2();
        void Make();
        void DrawEllipse();
        void Draw();

    private:
        ////////////////////////////////////////////////////////////
        /// \brief CalcEllipse
        ///
        /// \param x1     Left X coord
        /// \param y1     Bottom Y coord
        /// \param x2     Right X coord
        /// \param y2     Top Y coord
        ///
        ////////////////////////////////////////////////////////////
        void CalculateEllipse(int x1, int y1, int x2, int y2);

        Ellipse2() = delete;
        Ellipse2(const Ellipse2 &other) = delete;
        Ellipse2(Ellipse2 &&other) = delete;
        Ellipse2 &operator=(const Ellipse2 &other) = delete;
        Ellipse2 &operator=(Ellipse2 &&other) = delete;
    };
}

#endif