/*
https://codeforces.com/contest/845/problem/C

concept : greedy + sorting 


*/


#include <bits/stdc++.h>
using namespace std;

#define loop(i,a,b)     for(int i=(a); i<(b); i++)
#define all(x)          (x).begin(), (x).end()

bool IsOverlapping ( pair<int,int>&a, pair<int,int>&b){
    return a.second >= b.first ;
}

int main(int argc, char const *argv[]) { 

  int n; cin >> n;

  vector< pair <int,int>>arr;

  loop(i,0,n){
    int a, b;
    cin >> a >> b;
    arr.push_back({a,b});
  }

  sort( all(arr));    // on the basis of start time;

   pair<int,int> tv1 = {-1,-1}, tv2 = {-1,-1};
        bool ans = true;

   loop(i,0, n){
     
       if( !IsOverlapping( tv1, arr[i] )){
            tv1 = arr[i];
            continue;
       }else {
           if( !IsOverlapping(tv2,arr[i]) ){
               tv2 = arr[i];
               continue;
           }else{
             ans = false;
              break;
           }
       }
     
   }

     if( ans ) cout <<"YES\n";
     else cout <<"NO\n";

    return 0;
}