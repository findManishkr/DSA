/*

 https://codeforces.com/problemset/problem/891/A

 https://leetcode.com/problems/minimum-number-of-operations-to-make-all-array-elements-equal-to-1/description/


*/


#include <bits/stdc++.h>
using namespace std;

#define loop(i,a,b)     for(int i=(a); i<(b); i++)
#define all(x)          (x).begin(), (x).end()

int gcd( int a, int b){
      if( a == 0) return b;
     return gcd( b % a, a);
}

int main(int argc, char const *argv[]) { // setupIO();
      int n; cin >> n;

      vector<int>arr(n);
      loop(i,0,n) cin >> arr[i];

      int cnt1 = 0;
      loop(i,0,n) 
      if( arr[i] == 1) cnt1++;

         int ans ;
      if( cnt1 > 0 ){
          ans = n - cnt1;
      }else{
          // find out smallest segment of the array which gives the gcd 1 , if there is not segment 
          // which gives gcd one the , there is no way to transform all array el into 1, for that  
          // print -1;

            int res = INT_MAX;

            loop(i,0,n){
                   int g = arr[i];
                 loop(j, i+ 1, n){
                     g = gcd( g, arr[j]);

                     if( g == 1){
                         res = min( res, j -i + 1);
                          break;
                     }


                 }
            }

            ans  =  res == INT_MAX ? -1 : res + n -2;
      }


        cout << ans <<'\n';


    return 0;
}
