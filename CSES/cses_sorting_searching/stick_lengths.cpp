#include <bits/stdc++.h>
using namespace std;

#define loop(i,a,b)     for(int i=(a); i<(b); i++)
#define all(x)          (x).begin(), (x).end()
#define ll long long
#define inf INT_MAX

ll f( vector<ll>&arr, ll x, ll n){
     
      ll cost = 0;

      loop(i,0,n) 
      cost += abs(arr[i] - x);


   return cost;
}

int main(int argc, char const *argv[]) { 

ll n; cin >> n;
vector<ll>arr(n);
loop(i,0,n) cin >> arr[i];


sort(all(arr));

ll ans = (n % 2) ? f(arr, arr[n/2],n) : min( f(arr, arr[n/2],n),f(arr, arr[n/2-1],n));

cout << ans <<'\n';




  
    return 0;
}