/*
https://leetcode.com/problems/out-of-boundary-paths/?envType=problem-list-v2&envId=50wob6ze

 concept : one shot one kill problem

*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int M , N;
    const int mod = 1e9 + 7;
    vector <vector <int>>dir = { {1,0}, {-1,0}, {0,1}, {0,-1}};
    int dp[55][55][55];
    int f( int i, int j, int MaxMoves ){
   
        if( (i < 0 || j < 0 || j >= N || i >= M ) && MaxMoves >= 0 ) return 1;
        if( MaxMoves <= 0 ) return 0;
         
        if( dp[i][j][ MaxMoves] != -1 ) return dp[i][j][ MaxMoves] ; 
         
        int ans = 0;

        for( auto &x : dir ){
            int ni = i + x[0], nj = j + x[1];

            ans = ( (ans) % mod  +  f( ni, nj, MaxMoves -1 ) % mod ) % mod;
        }

        return  dp[i][j][ MaxMoves] =  ans;
       
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
          M = m;
          N = n;
        
         memset( dp, -1, sizeof( dp));
       
        return f( startRow, startColumn, maxMove);
    }
};

int main(){



    return 0;
}