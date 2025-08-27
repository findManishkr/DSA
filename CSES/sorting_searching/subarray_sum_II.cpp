#include <bits/stdc++.h>
using namespace std;



void setupIO() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

#define loop(i, a, b) for( int i = (a); i < (b); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long 

ll subarraySum(vector<int>& nums, int k) {
             int N = nums.size();
           ll count = 0, sum = 0;

          map < ll,ll> mp;
           

          
           mp[0] = 1;

           for( int i = 0; i < N; i++){
              sum += nums[i];

              if( mp.count( sum - k) ){
                  count += mp[ sum - k];
              }

              mp[sum]++;
           }

      return count;
    }

int main(){
      int n, target ;
      cin >> n >> target;

      vector <int>arr(n);
      loop(i,0,n) cin >> arr[i];

      cout << subarraySum( arr, target ) <<'\n';


    return 0;
}