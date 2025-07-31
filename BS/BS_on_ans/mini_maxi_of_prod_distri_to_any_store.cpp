#include <bits/stdc++.h>
using namespace std;

void setupIO() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif
}

class Solution {
public:
      bool f( vector <int>& arr, int mid, int n){
               int N = arr.size();

               int res = 0;
               for( int el : arr) res +=  (el + mid - 1)/mid;


          return res <= n;
      }
    int minimizedMaximum(int n, vector<int>& quantities) {
               int N  = quantities.size();

               int lo = 1, hi = *max_element( quantities.begin(), quantities.end());
                 int ans = 0;
               while( lo <= hi){

                int  mi = lo + (hi - lo)/2;

                   if( f( quantities, mi, n) ){
                         ans = mi;
                         hi = mi - 1;
                   }else 
                       lo = mi + 1;
               }

               return ans;
    }
};
int main() { setupIO();
    
    
    return 0;
}
