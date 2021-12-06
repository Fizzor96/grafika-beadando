#include "Binomial.h"

namespace eke
{

    KeyPair::KeyPair()
    {
    }

    KeyPair::KeyPair(const int &x, const int &y)
    {
        this->x = x;
        this->y = y;
    }

    KeyPair::~KeyPair()
    {
    }

    bool KeyPair::operator==(const KeyPair &obj) const
    {
        if (this->x == obj.x && this->y == obj.y)
        {
            return true;
        }
        return false;
    }

    BDict::BDict()
    {
    }

    BDict::BDict(const KeyPair &key, const long &val)
    {
        this->key.x = key.x;
        this->key.y = key.y;
        this->val = val;
    }

    BDict::~BDict()
    {
    }

    bool BDict::operator==(const BDict &obj) const
    {
        if (this->key.x == obj.key.x && this->key.y == obj.key.y && this->val == obj.val)
        {
            return true;
        }
        return false;
    }

    Binomial::Binomial()
    {
    }

    Binomial::~Binomial()
    {
    }

    long Binomial::GetBinom(const int &n, const int &k)
    {
        KeyPair key(n, k);

        for (unsigned int i = 0; i < this->cache.size(); i++)
        {
            if (this->cache[i].key == key)
            {
                return this->cache[i].val;
            }
        }

        long result = GetBinomRecursive(n, k);
        this->cache.push_back(BDict(key, result));
        return result;
    }

    long Binomial::GetBinomRecursive(const int &n, const int &k)
    {
        if (k == 0)
            return 1;
        return GetBinomRecursive(n, k - 1) * (n - k + 1) / k;
    }
}