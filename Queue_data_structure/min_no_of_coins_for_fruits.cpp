/*
 https://leetcode.com/problems/minimum-number-of-coins-for-fruits/

 concept : dp, optimization with queue


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

class Solution {
public:
       const int inf = INT_MAX;
       int dp[1005];
    int f( int idx, vector<int>&prices, int N) {
              if( idx >= N ) return 0;

                  if( dp[idx] != -1) return dp[idx];
                int res = inf;

              for( int i = idx + 1; i <= 2*idx + 2; i++ )
                  res = min( res, f(i, prices, N) );



       return dp[idx] =  prices[idx] + res;
    }
    int bottomUp ( vector<int>&prices ){
             int N = prices.size();
            vector< int > dp(2*N + 2,0 );

            for( int i = N - 1; i >= 0; i--){
                 dp[i] = inf;
                 for( int j = i + 1; j <= 2*i + 2; j++)
                 dp[i] = min( dp[i], dp[j]);

                dp[i] = dp[i] + prices[i];
            }


          return dp[0];
    }
    int minimumCoins(vector<int>& prices) {
           int N = prices.size();
            
             memset( dp, -1, sizeof(dp));

         //  return f(0, prices, N);

         return bottomUp( prices);
    }
};

// optimization 
 
// implement sliding window minimum solution



/*

 # decipher the problem statement correctly, as it has anomalies and it is cumbersome
     - consider 1 indexed array

     1.if you buy ith fruit for price == `price[i]` then you can get next `i` fruits for free
     2. even if you get jth fruit for free, you can purchase it to unlock its reward


 # to find/ return 
   - min no of coins need to buy all the fruits    


 # straight forward dp solution, with reccurence relation this


  f(idx,arr) -> returns the min  coin to buy all fruits

  f(idx,arr)  =      arr[idx] + min( f(j,arr) )   for all j belonging to [ idx + 1, 2*idx+2]

  worst case time comlexity is O(N^2)
  but can be opimized to\
     |-> as if we look at reccurence relation -> it hints towards `sliding window minimum`




*/

int main(int argc, char const *argv[]) { setupIO();



    return 0;
}