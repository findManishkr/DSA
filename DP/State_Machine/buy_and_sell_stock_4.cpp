#include <bits/stdc++.h>
using namespace std;

#define inf 1e9
class Solution {
public:
     vector < vector < vector < int>>>dp;
    int f( int idx, int k, bool ongoing , vector < int>& prices , int n){
           // base case 

           if( idx == n || k <= 0 ) return 0;


           if( dp[idx][k][ongoing] != -1) return dp[idx][k][ongoing ];   // ie ( idx, k, on) the state is already computed, use the stored result , if not computed computed

           int ans = -inf;

           if( !ongoing ){
               int buyNow =  f( idx + 1, k ,true, prices, n ) - prices[idx];
               // or buy on any other day
               int buyOtherDay = f( idx + 1, k , ongoing, prices, n);

               ans = max({ans, buyNow, buyOtherDay});

           }else{
               int sellNow = prices[idx] + f( idx + 1, k -1, false , prices, n);

               int sellOtherDay =  f( idx+1, k, ongoing, prices, n);

                ans = max( {ans, sellNow, sellOtherDay}); 



           }

             



      return  dp[idx][k][ongoing ] = ans;
    }
    int maxProfit(int k, vector<int>& prices) {
                  int n = prices.size();
               dp.assign( n+ 2, vector<vector<int>>(k+1, vector<int>(2, -1)));

        return f( 0, k, false, prices, n);
    }
};


/*

f( idx, k, on ) -> returns the max profit obtained form index idx to N -1;

idx -> index from we starting 
k -> transcitions left
ongoing -> holding a stock or not {

If holding → {sell, hold}

If not holding → {buy, skip}

};

tc : word per subproblem * no of sub problem

tc = O(1) * O( n, k, 2);

tc = O( n * k * 2);

sc : O( maxDepthofrecusion) + O( dptable ) ie :-> O(n) + O( n*k*2)



*/


int main(){




    return 0;
}