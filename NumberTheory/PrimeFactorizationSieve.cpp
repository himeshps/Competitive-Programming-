int MAXN=1e6+1;
vector<int> spf(MAXN + 1, 1);

void sieve()
{
    spf[0] = 0;             //spf is the smallest prime factor 
    for (int i = 2; i <= MAXN; i++) {
        if (spf[i] == 1) { 
            for (int j = i; j <= MAXN; j += i) {
                if (spf[j]== 1) 
                    spf[j] = i;
            }
        }
    }
}  // Sieve works at O(n log(log n))

vector<int> getFactorization(int x)
{
    vector<int> ret;
    while (x != 1) {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}

// Post pre-computation, the individual queries can be answered in O ( log N ) time complexity.
