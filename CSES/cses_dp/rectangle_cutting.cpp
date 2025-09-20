/*

https://cses.fi/problemset/submit/1744/


*/


#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define inf 1e18
#define loop(i,a,b)  for( int i = (a); i <(b);i++) 

ll dp[505][505];

ll f( ll a, ll b){
     if( a == b ) return 1;


       if( dp[a][b] != -1) return dp[a][b];

      ll ans = inf;

     // horizontal cut;
     // horizontal cut a varies from [1 to a - 1]

     loop(i, 1, a)
     ans = min( ans, f(i,b) + f(a - i, b) );



     // vertical cut; 
     // in vertical cut b varies from [1 to b-1];

       loop(i,1,b)
     ans = min( ans, f(a,i) + f(a, b -i));




  return dp[a][b] =  ans;
}

int main(){


ll a, b;
cin >> a >> b;

  memset(dp, -1, sizeof(dp));

cout << f(a,b)-1 <<'\n';

  

    return 0;
}