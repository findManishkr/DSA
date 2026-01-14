/*

https://codeforces.com/contest/431/problem/C

concept : dp + observation of recursion tree




*/

#include <bits/stdc++.h>
using namespace std;


void setupIO() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}
const int mod = 1e9 + 7;
int dp[105][2];

int f( int sum, int k,int d, int n, bool Iscontains_d){
             /*
             
              time comlexity:
                 
               o( sum ) * O(k) = o(sum *k)
             
              
             */

        if( sum > n ) return 0;

        if( sum == n )
        return  Iscontains_d ? 1 : 0;

        if( dp[sum][Iscontains_d] != -1) return dp[sum][Iscontains_d];
      

        int res = 0;

        for( int i = 1; i <= k ; i++)
        res = (res + f( sum + i, k, d, n, Iscontains_d | ( i >= d)  )) % mod  ;
      
        return dp[sum][Iscontains_d] = res;
}


int main(int argc, char const *argv[]) { setupIO();
     
    int n, k , d;
    cin >> n >> k >> d;

    memset(dp, -1, sizeof(dp));

    cout << f(0, k, d, n, false) <<'\n';


    return 0;
}