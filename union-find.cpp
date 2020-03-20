#include <bits/stdc++.h>

struct UnionFind {
    vector<int> par;

    UnionFind(int n) {
        for (int i = 0; i < n; i++) par.push_back(i);
    }

    int root(int x) {
        if (par[x] == x) return x;
        else return par[x] = root(par[x]);
    }

    bool same(int x, int y) {
        return root(x) == root(y);
    }

    void unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return;
        par[x] = y;
    }
};
