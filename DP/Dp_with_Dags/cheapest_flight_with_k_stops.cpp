/*

https://leetcode.com/problems/cheapest-flights-within-k-stops/?envType=problem-list-v2&envId=2g29d5jd


concept : dp with dags


*/


#include <bits/stdc++.h>
using namespace std;

#define inf 1e9 
class Solution {
public:
      vector < vector < pair<int,int>>> graph;
       vector < vector <int>>dp;
    int f( int src, int k , int dest ){
        
          if( k < 0 )  return inf;
          if( src == dest && k >= 0 ) return 0;

           if( dp[src][k] != -1) return dp[src][k];

          int res = inf;

          for( auto [nbd, price] : graph[ src ]){
             int temp = f( nbd, k - 1, dest);

             if( temp != inf ) 
             res = min( res, temp + price );

          }

       return  dp[src][k] =  res;
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
         graph.assign( n, {});
         dp.assign(n, vector <int>(k+2, -1));

          for( auto x : flights)
             graph[x[0]].push_back({x[1], x[2]} );
          
           int ans = f( src, k + 1, dst);

         return ( ans == inf ? -1 : ans);      
    }
};

int main(){




    return 0;
}