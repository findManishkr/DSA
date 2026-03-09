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

#define ll long long
class Solution {
public:
    const ll inf = 1e18;
    int smallestBalancedIndex(vector<int>& nums) {
         int n = nums.size();

         vector<ll>suffpro(n+1, 1LL);      // suffix product
         vector<ll>prefsum(n+1, 0LL);



         const ll Limit = 1e18;

         for( int i = n -1; i >= 0; i--){
            if( suffpro[i+1] > ( Limit/ (1LL*nums[i]) ))    // how ?
            suffpro[i] = Limit;
            else
             suffpro[i] = nums[i] * suffpro[i+1];
         }

         for( int i = 0; i < n; i++){
             prefsum[i+1] = 1LL*nums[i] + prefsum[i];
         }
          
          for( int i = 0; i < n; i++){
              if( suffpro[i+1] == prefsum[i])
              return i;
          }
         return -1;
    }
};


/*


 # Question
  - how to avoid `integer overflow while doing repeated continuosly multiplication`?
     answer = `product capping `




*/

int main(int argc, char const *argv[]) { setupIO();



    return 0;
}