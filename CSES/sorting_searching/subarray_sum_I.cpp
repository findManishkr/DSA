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
          /*
            prefix sum + hashmap approach

             works for -ve values array also 
          
          
          */


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




    ll SubarraySum(vector<int>& nums, int k) {
          /*
            prefix sum + 2 pointer apporach 
          
          */


          int N = nums.size();
          vector <ll>psum(N);
        
         
          psum[0] = nums[0];
          for( int i = 1; i < N; i++)
          psum[i] = psum[i-1] + nums[i];

          int i = 0, j = 0;

          ll cnt = 0;

          while( j < N && psum[j] <= k ){
             if( psum[j] == k) cnt++;
             j++;
          }
          
          while( i < N && j < N ){
             
             if( (psum[j] - psum[i]) == k){
                 cnt++;
                 j++;
             }
             else if( (psum[j] - psum[i]) > k)i++;
             else j++;

          }

      return cnt;
    }
  
  // sliding window approach 

  ll f( vector <int>&arr, int k ){
            int N = arr.size();
       ll left = 0, cnt = 0;
       ll sum = 0;

       for( ll right = 0; right < N ; right++){
               sum += arr[ right ];

                while( sum > k ){
                      sum -= arr[left];
                      left++;
                }

                cnt += ( sum == k ) ? 1 : 0;
       }

       return cnt;

  }
int main(){
      int n, target ;
      cin >> n >> target;

      vector <int>arr(n);
      loop(i,0,n) cin >> arr[i];

      cout << subarraySum( arr, target ) <<'\n';


    return 0;
}