/*


https://leetcode.com/problems/fill-a-special-grid/



*/



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

/*

# time complexity


Example

T(n)=T(n−1)+4n

Expand
4^n + 4n^−1 + 4n^−2 + ⋯

Largest term dominates.

Answer

O(4^n) 


tc = O(4^n)



# space complexity

f(3)
│
├── f(2)
│   │
│   ├── f(1)
│   │
│   └── creates 2×2 matrix
│
└── creates 4×4 matrix


At the deepest point after recursion unwinds, the matrices simultaneously alive are

1×1,2×2,4×4,8×8,…,2n×2n  = 1 , 4 , 4^2 ... 4^n  

sc = 1 + 4 + ... 4^n = (4 * (4^n-1))/3;

which is order of 4^n

sc = 0(4^n)


Hence 

tc = O(4^n)
sc = o(4^n)


*/