/*


https://codeforces.com/contest/1648/problem/A

concept : sharp observation + sorting

 bottleneck of the problem :     |x1 - x2| + |y1 - y2|

*/

#include <bits/stdc++.h>
using namespace std;

#define loop(i,a,b)     for(int i=(a); i<(b); i++)
#define all(x)          (x).begin(), (x).end()
#define ll long long
#define pll pair<ll, ll>
void setupIO() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}
const ll mx = 1e5 + 1;

ll f( vector<ll>&arr ){

        ll N = arr.size();

         sort(all(arr));

          ll res = 0;
          for( ll i = 0; i < N; i++){
              res += i * arr[i];
          }
          for( ll i = N - 1; i >= 0; i--){
              res -=  i * arr[N-i -1];
          }

          res = res < 0 ? -1*res : res;

          return res;
}
int main(int argc, char const *argv[]) { setupIO();

       ll n, m;
       cin >> n >> m;

       map < ll, vector<ll>>mp1, mp2;

       loop(i,0,n){
        loop(j,0,m){
             ll x; cin >> x;
             mp1[x].push_back(i);
             mp2[x].push_back(j);
        }
       }
          ll res = 0;
        for( auto x : mp1){
             res += f(x.second);
        }

         for( auto x : mp2){
             res += f(x.second);
        }

        cout << res <<'\n';

    return 0;
}