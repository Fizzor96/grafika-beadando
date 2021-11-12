using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GrafikaDLL
{
    public abstract class ABinomial
    {
        public abstract long Binom(int n, int k);
    }

    public class Binomial : ABinomial
    {
        class BinomialRecursive : ABinomial
        {
            public override long Binom(int n, int k)
            {
                //if (k == 0 || k == n) return 1;
                //if (n == 0) return 0;
                //return Binom(n - 1, k - 1) + Binom(n - 1, k);
                if (k == 0) return 1;
                return Binom(n, k - 1) * (n - k + 1) / k;
            }
        }

        BinomialRecursive br = new BinomialRecursive();
        Dictionary<KeyPair, long> cache = new Dictionary<KeyPair, long>();

        public override long Binom(int n, int k)
        {
            KeyPair key = new KeyPair(n, k);
            if (cache.ContainsKey(key))
                return cache[key];
            long result = br.Binom(n, k);
            cache.Add(key, result);
            return result;
        }
    }
}
