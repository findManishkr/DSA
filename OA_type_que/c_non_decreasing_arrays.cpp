/*

https://codeforces.com/contest/2144/problem/C

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
#define mod 998244353
#define ll long long


int n;
vector<int>a, b;
int dp[105][2];

int f( int idx, int PrevSwap){
     /*
       time : O(N *2)
       space :O(N *2)
     
     */


       
     if( idx  == n) return 1;

          if( dp[idx][ PrevSwap] != -1 ) return  dp[idx][ PrevSwap];

      int prevA =  !PrevSwap ? a[idx-1] : b[idx-1];
      int prevB =  !PrevSwap ? b[idx-1] : a[idx-1];

        ll  ans = 0;

      // swap at index `idx`;
        if( prevA <= b[idx] && prevB <= a[idx])
        ans  =  (ans +  f( idx + 1 , true) ) % mod;

      // don't swap at indxex`idx`  
        if( prevA <= a[idx] && prevB <= b[idx])
        ans  = ( ans +  f( idx + 1 ,false) ) % mod;



  

    return   dp[idx][ PrevSwap] =  (ans % mod);
}

int main(int argc, char const *argv[]) { setupIO();
 int t; cin >> t;
  while(t--){


     cin >> n;
     a.resize(n), b.resize(n);
     loop(i,0,n) cin >> a[i];
     loop(i,0,n) cin >> b[i];

      
     memset( dp, -1, sizeof(dp));


      ll ans = 0;

      ans = (ans + f(1,0) )%mod;
      ans = ( ans + f(1,1)) % mod;

      cout << ans <<'\n';

  }


    return 0;
}