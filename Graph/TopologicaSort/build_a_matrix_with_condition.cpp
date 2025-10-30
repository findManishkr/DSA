/*

 https://leetcode.com/problems/build-a-matrix-with-conditions/?envType=problem-list-v2&envId=2g29d5jd

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> KAHNS_ALGO(vector<vector<int>>& edges, int k) {

        vector<int> indegree(k + 1, 0); // nodes are labled as [1,2....k]

        vector<vector<int>> graph(k + 1, vector<int>());

        // calculate the indegree of each node

        for (auto x : edges) {
            int u = x[0], v = x[1];
            graph[u].push_back(v);
            indegree[v]++;
        }

        // now pick the nodes with zero indegree, place them in a queue

        queue<int> q;

        for (int i = 1; i <= k; i++)
            if (!indegree[i])
                q.push(i);

        vector<int> topoOrder;

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            topoOrder.push_back(node);

            for (int nbd : graph[node]) {
                if (!(--indegree[nbd]))
                    q.push(nbd);
            }
        }

        return (topoOrder.size() == k) ? topoOrder : vector<int>();
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions,
                                    vector<vector<int>>& colConditions) {

        // row graph construction

        vector<int> roworder = KAHNS_ALGO(rowConditions, k);
        vector<int> colorder = KAHNS_ALGO(colConditions, k);

        if (roworder.empty() || colorder.empty())
            return {};

        map<int, int> mp;

        for (int i = 0; i < colorder.size(); i++)
            mp[colorder[i]] = i;

        vector<vector<int>> ans(k, vector<int>(k, 0));

        for (int i = 0; i < roworder.size(); i++) {

            int j = mp[roworder[i]];

            ans[i][j] = roworder[i];
        }

        return ans;
    }
};

int main(int argc, char const *argv[]) { 



    return 0;
}