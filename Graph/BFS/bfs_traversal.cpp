/*

 https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1


*/


#include <bits/stdc++.h>
using namespace std;
void setupIO() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif
}

class Solution {
public:
    vector<int> bfs(vector<vector<int>> &adj) {
        int N = adj.size();
        
        vector<int> ans;               // Stores BFS traversal order
        vector<bool> vis(N, false);    // Marks visited nodes
        vector<int> dist(N, -1);       // Stores shortest distance from source
        vector<int> parent(N, -1);     // Stores parent of each node in BFS tree

        int srcNode = 0;               // Let's assume node 0 is the source
        queue<int> q;

        q.push(srcNode);
        vis[srcNode] = true;
        dist[srcNode] = 0;

        while (!q.empty()) {
            int node = q.front(); q.pop();
            ans.push_back(node);       // Process current node

            for (int neighbor : adj[node]) {
                if (vis[neighbor]) continue;

                vis[neighbor] = true;
                dist[neighbor] = dist[node] + 1;
                parent[neighbor] = node;
                q.push(neighbor);
            }
        }

        return ans;
    }
};




int main(){





    
    return 0;
}
