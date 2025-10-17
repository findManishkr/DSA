


#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;

void dfs_down(int node, int par, vector<int>& downDist) {
    downDist[node] = 0;
    for (int nbd : graph[node]) {
        if (nbd == par) continue;
        dfs_down(nbd, node, downDist);
        downDist[node] = max(downDist[node], 1 + downDist[nbd]);
    }
}

void dfs_up(int node, int par, vector<int>& upDist, vector<int>& downDist) {
    int max1 = -1, max2 = -1;

    // find top 2 longest downward paths from this node
    for (int nbd : graph[node]) {
        if (nbd == par) continue;
        int val = 1 + downDist[nbd];
        if (val > max1) {
            max2 = max1;
            max1 = val;
        } else if (val > max2) {
            max2 = val;
        }
    }

    // now pass upDist info to children
    for (int nbd : graph[node]) {
        if (nbd == par) continue;

        int use = (1 + downDist[nbd] == max1 ? max2 : max1);
        upDist[nbd] = max(upDist[node] + 1, (use == -1 ? 0 : use + 1));

        dfs_up(nbd, node, upDist, downDist);
    }
}

int main() {
    int n;
    cin >> n;
    graph.resize(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> downDist(n + 1, 0), upDist(n + 1, 0);
    dfs_down(1, -1, downDist);
    upDist[1] = 0; // root's upward distance = 0
    dfs_up(1, -1, upDist, downDist);

    vector<int> maxDist(n + 1, 0);
    for (int i = 1; i <= n; i++)
        maxDist[i] = max(downDist[i], upDist[i]);

    for (int i = 1; i <= n; i++)
        cout <<   maxDist[i] << ' ';
}
