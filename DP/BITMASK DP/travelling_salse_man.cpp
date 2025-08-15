/*
https://www.geeksforgeeks.org/problems/travelling-salesman-problem2732/1

concept : dp + bitmask

*/

#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;


class Solution {
  public:
     int N;
    vector < vector <int>>dp;
    int f( int curr, int mask, vector<vector<int>>&cost ){
        // base case 
            if( mask ==  (( 1 << N ) -1) )
             return cost[ curr ][ 0 ];
        
        
        if( dp[curr][mask] != -1) return dp[curr][ mask];
        
        int ans = inf;
        
        for( int nbd = 0 ; nbd < N; nbd++ ){
             
             if( (mask & ( 1 << nbd)) == 0 )
             ans = min( ans, cost[curr][ nbd] + f( nbd, (  mask | ( 1 << nbd) ), cost )  );
            
        }
        
        return dp[ curr ][ mask] =  ans;
    }
    int tsp(vector<vector<int>>& cost) {
         N = cost.size();
            int mask = 1;    // as initially only 0th bit is set
            
            dp.assign(N+1, vector <int>( (1 << (N+1)) , - 1) );
        
        return f(0, mask, cost);
    }
};
int main(){



    
    return 0;
}