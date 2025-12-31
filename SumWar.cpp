#include <bits/stdc++.h>
using namespace std;

struct DSU
{
    vector<int> parent, sz;

    DSU(int n)
    {
        parent.resize(n);
        sz.assign(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]); // path compression
    }

    bool unite(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a == b)
            return false;

        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        return true;
    }

    bool same(int a, int b)
    {
        return find(a) == find(b);
    }

    int size(int x)
    {
        return sz[find(x)];
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    DSU dsu(n + 1);
    while (m--)
    {
        int l, r;
        cin >> l >> r;
        dsu.unite(l - 1, r);
    }
    map<int, int> mp;
    int curr = 1;
    vector<int> ps(n + 1, 0);
    for (int i = 0; i <= n; i++)
    {
        int root = dsu.find(i);
        if (!mp.count(root))
            mp[root] = curr++;
        ps[i] = mp[root];
    }

    for (int i = 1; i <= n; i++)
    {
        cout << ps[i] - ps[i - 1] << " ";
    }
    cout << "\n";
    return 0;
}