/*
https://cses.fi/problemset/result/14677306/


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


int main(int argc, char const *argv[]) {  setupIO();

   int n, x;
   cin >> n >> x;

    vector<vector<int>>arr(n);
    loop(i,0,n){
        int a; cin >> a;
        arr[i] = {a,i+1};
    }

    sort( all(arr));

    int i = 0, j = n -1;
       while( j -i >= 1 ){
            
          if( arr[i][0] + arr[j][0] == x){
               cout << arr[i][1] <<' '<< arr[j][1] <<'\n';
               return 0;
          }else if( arr[i][0] + arr[j][0] < x) i++;
          else j--;
         
       }

       cout << "IMPOSSIBLE\n";

    return 0;
}