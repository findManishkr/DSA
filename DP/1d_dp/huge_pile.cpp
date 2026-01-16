/*


https://codeforces.com/contest/2184/problem/C



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

const int inf = 1e9 + 7;
int f( int n, int k, map< int,int>&dp){
      if( n < k ) return inf;
      if( n == k) return 0;

     if( dp.count(n) ) return dp[n];
    
     int ans = 0;
     if( n % 2 )
     ans  =  min( f(n/2,k,dp), f(n -n/2, k,dp));
     else 
     ans =  f(n/2,k,dp);

     return dp[n] =  1 + ans;

}

int main(int argc, char const *argv[]) { setupIO();
     int t; cin >> t;
     while(t--){
        int n, k; 
        cin >> n >> k;

        map< int,int>dp;

        int ans = f(n,k,dp);

        if( ans >= inf)
        cout << -1 <<'\n';
        else
          cout << ans <<'\n';


     }
 

    return 0;
}