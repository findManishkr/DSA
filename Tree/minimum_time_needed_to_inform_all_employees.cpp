
#include <bits/stdc++.h>
using namespace std;

void setupIO() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif
}

int v;
vector<vector<int>> Tree;
vector<int> ss;


void f(int node, int par ) {

    ss[node] = node; 

    for (int nbd : Tree[node]) {
        if (nbd == par) continue;
        f(nbd, node);
    }


    if (par != -1)
        ss[par] += ss[node];
}
int main() {
    setupIO();

    cin >> v;              
    ss.resize(v + 1, 0);    

    for (int i = 1; i < v; i++) {
        int u, vv;
        cin >> u >> vv;
        Tree[u].push_back(vv);
        Tree[vv].push_back(u);
    }

    f(1,-1);

    for (int i = 1; i <= v; i++)
        cout << i << ' ' << ss[i] << '\n';  

    return 0;
}
