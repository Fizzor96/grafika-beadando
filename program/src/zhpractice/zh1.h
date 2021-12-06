#ifndef ZH1PRACTICE_HPP
#define ZH1PRACTICE_HPP 1

#include "Core.h"
#include "MyRect.h"
#include <SFML/Graphics.hpp>
#include <random>
#include <time.h>
#include <vector>

namespace eke
{
    class MyRect;

    class zh1
    {
    public:
        std::vector<MyRect *> rectvec;
        std::vector<Hermite2Arc *> hermites;

    public:
        void Update();
        void Draw();
        void ReCalcHermites();

    public:
        zh1();
        ~zh1();

    private:
        bool isgrabbed;
        void CreateSetRect();
        void Clear();
    };
}

#endif