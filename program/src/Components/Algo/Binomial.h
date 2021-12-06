#ifndef BINOMIAL_HPP
#define BINOMIAL_HPP 1

#include <vector>

namespace eke
{
    class KeyPair
    {
    public:
        int x, y;
        KeyPair();
        KeyPair(const int &x, const int &y);
        ~KeyPair();
        bool operator==(const KeyPair &obj) const;
    };

    class BDict
    {
    public:
        long val;
        KeyPair key;
        BDict();
        BDict(const KeyPair &key, const long &val);
        ~BDict();
        bool operator==(const BDict &obj) const;
    };

    class Binomial
    {
    private:
        std::vector<BDict> cache;

    public:
        Binomial();
        long GetBinom(const int &n, const int &k);
        long GetBinomRecursive(const int &n, const int &k);
        ~Binomial();
    };
}

#endif