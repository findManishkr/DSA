/*


https://codeforces.com/contest/276/problem/C

concept : diff array techniuq + sorting + observations

*/



#include <bits/stdc++.h>
using namespace std;
 


#define loop(i,a,b) for( int i= (a) ; i <(b); i++)
#define ll long long 

int main(){

    ll n, q;
    cin >> n >> q;

    vector < ll > arr(n + 1);
    loop( i, 1, n + 1) cin >> arr[i];

     
    vector < ll > diff( n + 2,0);  // difference array

     loop(i,0, q){
        ll l, r;
        cin >> l >> r;

         diff[l] += 1;
         diff[r+1] -= 1;
     }

     // now take prefix sum of to get freq. of each index
      loop(i,2, n+1)
      diff[i] = diff[i] + diff[i-1];

      sort( arr.begin()+1, arr.end());
      sort( diff.begin()+1, diff.end()-1);

      ll ans = 0;

      loop(i,1,n+1)
      ans += arr[i] * diff[i];


        cout << ans <<'\n';

  return 0;
}
  
