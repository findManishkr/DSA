/*

https://codeforces.com/contest/627/problem/A


*/

#include <bits/stdc++.h>
using namespace std;

#define loop(i,a,b)     for(int i=(a); i<(b); i++)
#define all(x)          (x).begin(), (x).end()
#define ll long long 

ll f( ll s, ll x){


      ll diff = s - x;

      ll ans = 0;

     if( diff < 0 || diff % 2 ){
        return ans;
     }

     // check no overlap between c and x 
     ll c = diff/2;
     if( (c &x) != 0 ){
        return ans;
     }

     ll bits = __builtin_popcountll(x);

     ans = (1LL << bits);

     if( s == x )  ans -= 2;     // remove ( 0, s) and (s,0)


     return ans;

}
int main(int argc, char const *argv[]) {


    /*
       a+b = a^b + 2*(a&b)
    */

     ll s , x ;
     cin >> s >> x;

     
  
       cout << f(s,x) <<'\n';

   


    return 0;
}