// this is my new implementation as the last one's internals were purely shitty as fck. 

class UnionFind
{
private:
    vector<int> par;                // parent
    vector<int> sz;                 // size
 
public:
    UnionFind(int n)                    // using this OG constructor shit !!
    {
        par = vector<int>(n);
        iota(par.begin(), par.end(), 0);
        sz = vector<int>(n, 1);
    }
 
    int find(int u)                       // ultimate ancestor matching functionality .
    {
        if (par[u] != par[par[u]])
            par[u] = find(par[par[u]]);
        return par[u];
    }
 
    bool connected(int u, int v)         // the boolean returns a check if the given arguements to it are connected or not. 
    {
        u = find(u);
        v = find(v);
        if (u == v)
            return true;
        return false;
    }
 
    bool join(int u, int v)              // an important dude in the code, it combines the nodes into one segment . 
    {
        u = find(u);
        v = find(v);
        if (u == v)
            return false;
        if (sz[u] <= sz[v])
        {
            sz[v] += sz[u];
            par[u] = v;
        }
        else
        {
            sz[u] += sz[v];
            par[v] = u;
        }
        return true;
    }
};
