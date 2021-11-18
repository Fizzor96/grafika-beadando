#ifndef ELLIPSE2_HPP
#define ELLIPSE2_HPP 1

#include <SFML/Graphics.hpp>
#include "Core/Globals.h"
#include "Pixel.h"
#include <math.h>
#include <vector>
#include <iostream>

namespace eke
{
    class Ellipse2
    {
    public:
        std::vector<eke::Pixel *> vertexarr;
        std::vector<sf::Vector2f> positions;

        ////////////////////////////////////////////////////////////
        /// \brief Ellipse ctor
        ///
        /// \param x1     Left X coord
        /// \param y1     Bottom Y coord
        /// \param x2     Right X coord
        /// \param y2     Top Y coord
        ///
        ////////////////////////////////////////////////////////////
        Ellipse2(int leftX, int botY, int rightX, int topY);
        ~Ellipse2();
        void Draw();
    };
}

#endif