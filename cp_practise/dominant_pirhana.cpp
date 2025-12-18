/*


https://codeforces.com/contest/1433/problem/C

concept: observation


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

int main(int argc, char const *argv[]) { setupIO();

    int t; cin >>t;
    while(t--){
     
        int n; cin >> n;
        vector < int> arr(n);
        loop(i,0,n) cin >> arr[i];

        int maxval =  *max_element(all(arr));

           int idx = -1;
        loop( i ,0, n){
            if( arr[i] == maxval){
                if( (i -1 >=0 && arr[i-1] < arr[i]) || (i + 1 < n && arr[i+1] < arr[i]) ){
                     idx = i+ 1;
                     break;
                }
            }
        }

              cout << idx <<'\n';

    }


    return 0;
}


/*

   logic:

    maxsize pirhana can eat all smaller pirhana, provided it is strictly bigger 
    than all of its neighbours






*/