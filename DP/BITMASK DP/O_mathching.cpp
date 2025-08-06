/*

https://atcoder.jp/contests/dp/tasks/dp_o

concept : dp + bitmasking


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
    const int mod = 1000000007;

    int N; 
    vector < vector < int >> c;
    vector < vector <int>>dp;


int f( int i, int mask ){

    // base case 
      if( i == N + 1){
        if( !mask ) return 1;
        return 0;
      }
   
      if( dp[i][ mask] != -1) return dp[i][mask];
    
      int res = 0;

      for( int j = 0; j < N; j++){

          bool available =  ( (mask & ( 1 << j)) == 0) ? 0 : 1 ;

          if(  available  &&  c[i][j+1] )
           res  =  ( res +  f( i + 1, mask ^ ( 1 << j) ) ) % mod;
      }


        
     return  dp[i][mask] = res % mod ;
}




int main() {  setupIO();
    
               cin >> N;
     c.assign( N + 1, vector < int>(N+1));    // c:-> compatibility matrix

    for( int i = 1; i <=  N; i++){
        for( int j = 1; j <= N; j++){
             cin >> c[i][j];
        }
    }

     dp.resize( N + 1 , vector < int >( (1 << N )+ 2, -1));
      cout << f(1, ( 1 << N ) - 1 );
      
    return 0;
}
