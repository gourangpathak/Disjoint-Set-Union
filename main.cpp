#include<bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> rank, parent, size;
    public:
    DisjointSet(int n)
    {
        // To handle both 1 based and 0 based indexing
        rank.resize(n+1, 0);
        size.resize(n+1, 1);
        parent.resize(n+1);

        for(int i=0; i<n+1; i++)
            parent[i] = i;
    }

    int findPar(int node) {
        if(node == parent[node])
            return node;
        return parent[node] = findPar(parent[node]);
    }

    void UnionByRank(int u, int v)
    {
        int pu = findPar(u);
        int pv = findPar(v);

        if(pu == pv) return;

        if(rank[pu] > rank[pv])
        {
            parent[pv] = pu;
        }
        else if(rank[pu] < rank[pv]){
            parent[pu] = pv;
        }
        else {
            parent[pu] = pv;
            rank[pu]++;
        }
    }

    void UnionBySize(int u, int v)
    {
        int pu = findPar(u);
        int pv = findPar(v);

        if(pu == pv) return;

        if(size[pu] > size[pv])
        {
            parent[pv] = pu;
            size[pu]+=size[pv];
        }
        else if(size[pu] < size[pv]){
            parent[pu] = pv;
            size[pv]+=size[pu];
        }
        else {
            parent[pu] = pv;
            size[pv]+=size[pu];
        }
    }
};

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    DisjointSet ds(7);

    ds.UnionBySize(1,2);
    ds.UnionBySize(2,3);
    ds.UnionBySize(4,5);
    ds.UnionBySize(6,7);
    ds.UnionBySize(5,6);
    cout << "Before Union\n";
    if(ds.findPar(3) == ds.findPar(7))
        cout << "3 and 7 belong to same component\n";
    else cout << "3 and 7 belong to different component\n";
    ds.UnionBySize(3,7);
    cout << "After Union\n";
    if(ds.findPar(3) == ds.findPar(7))
        cout << "3 and 7 belong to same component\n";
    else cout << "3 and 7 belong to different component\n";

    return 0;
}