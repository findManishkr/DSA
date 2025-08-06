/*


https://leetcode.com/problems/redundant-connection/


concept : simple DSU

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    class DSU {
    public:
        int n;
        vector<int> par;
        vector<int> rank;

        DSU(int n) {
            this->n = n;

            par.resize(n + 1);
            for (int i = 1; i <= n; i++)
                par[i] = i;
            rank.resize(n + 1, 0);
        }

        int find(int x) {
            if (par[x] == x)
                return x;

            return par[x] = find(par[x]);
        }

        bool unite(int a, int b) {

            a = find(a);
            b = find(b);

            if (a == b)
                return true;

            if (rank[a] > rank[b])
                par[b] = a;
            else if (rank[b] > rank[a])
                par[a] = b;
            else
                par[b] = a, rank[a]++;

            return false;
        }
    };
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        DSU dsu(edges.size());
        for (int i = 0; i < edges.size(); i++) {

            if (dsu.unite(edges[i][0], edges[i][1]))
                return {edges[i][0], edges[i][1]};
        }

        return {};
    }
};

int main(){




    return 0;
}