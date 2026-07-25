#include <bits/stdc++.h>
using namespace std;

#define loop(i,a,b)     for(int i=(a); i<(b); i++)
#define all(x)          (x).begin(), (x).end()

void setupIO() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

// solution 1:  Recursion based ( like computing factorial ans = n * f(n-1))

class Solution {
public:
    vector<vector<int>> f(int n) {
        // base case

        if (n == 0)
            return {{0}};
        if (n == 1)
            return {{3, 0}, {2, 1}};

        auto prev = f(n - 1); // prev result

        // make ans using prev result;

        int sz = 1 << (n - 1);
        int val = sz * sz;

        vector<vector<int>> curr(2 * sz, vector<int>(2 * sz, 0));

        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < sz; j++) {
                // top right
                curr[i][j + sz] = 0 * val + prev[i][j];
                // bottom right
                curr[i + sz][j + sz] = 1 * val + prev[i][j];
                // bottom left
                curr[i + sz][j] = 2 * val + prev[i][j];
                // top left
                curr[i][j] = 3 * val + prev[i][j];
            }
        }

        return curr;
    }
    vector<vector<int>> specialGrid(int n) {
        
        vector<vector<int>> ans = f(n);

        return ans;
    }
};


int main(int argc, char const *argv[]) { setupIO();



    return 0;
}