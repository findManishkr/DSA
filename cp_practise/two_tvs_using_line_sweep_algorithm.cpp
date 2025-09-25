#include <bits/stdc++.h>
using namespace std;

#define loop(i,a,b)     for(int i=(a); i<(b); i++)
#define all(x)          (x).begin(), (x).end()

int f( vector< pair<int,int> >&arr, int n){

     vector< vector<int>>Events;

      loop(i,0,n){

          Events.push_back( {arr[i].first, +1});
          Events.push_back( {arr[i].second,-1});
      }

      sort( Events.begin(),Events.end(), []( const vector<int>&a, const vector<int>&b){
            if( a[0] == b[0]) return b[1] < a[1];
            return a[0] < b[0];
      });

      int currMax = 0, MaxTvRequired = 0;

      loop( i, 0, Events.size()){
         currMax += Events[i][1];
         MaxTvRequired = max( currMax, MaxTvRequired);
      }

      return MaxTvRequired ;

}

int main(int argc, char const *argv[]) { 

     int n; cin >> n;

     vector< pair<int,int>>arr;
     loop(i,0,n){
        int l, r; cin >> l >> r;
          arr.push_back({l,r});
     }

     int MaxTvReq = f(arr, n );
     if( MaxTvReq <= 2) cout <<"YES\n";
     else cout <<"NO\n";


    return 0;
}