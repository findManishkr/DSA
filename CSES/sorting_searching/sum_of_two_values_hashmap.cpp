/*
  time : o(N)
  space : O(N) due to map

  works for -ve array values also


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

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
                int N = nums.size();
    map<int,int>seen;     //  {key = nums[i], value = i}

              vector< int > res;

           for( int i = 0; i < N; i++ ){
            
            if( seen.count( target - nums[i] ) ){
                 
                  int idx1 = min( i, seen[ target - nums[i] ] );
                  int idx2 = max( i, seen[ target - nums[i] ]  );

                  res.push_back( idx1);
                  res.push_back( idx2);

                   break;


            }else{
                seen[  nums[i] ] = i;
            }  


          }

          return  res;
    }
};
int main(int argc, char const *argv[]) { setupIO();
     
      int n , x;
      cin >> n >> x;

      vector<int>arr(n);
      loop(i,0,n) cin >> arr[i];

      Solution sol;
    
      vector <int> ans = sol.twoSum( arr,x);

      if( ans.empty()) cout << "IMPOSSIBLE\n";
      else cout << ans[0] +1<<' ' << ans[1] + 1<<'\n';


    return 0;
}