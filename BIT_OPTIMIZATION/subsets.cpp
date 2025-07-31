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
    vector<vector<int>> subsets(vector<int>& nums) {
        
            int N =nums.size();

               vector<vector<int>> ans( 1 << N );    // there are (2^N ) possible subsets

                      
               for( int mask = 0; mask < ( 1 << N)  ; mask++){          // mask represents subsets   
                      
                   for(  int i = 0; i < N; i++){
                       if( mask & ( 1 << i ) )    // in a subset if ith bit is set , then include nums[i], else exclude
                        ans[ mask ].push_back( nums[i] );
                   }

                 

               }
            
       return ans;
    }
};

int main() { setupIO();
    
    
    return 0;
}
