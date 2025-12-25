/*

https://leetcode.com/problems/top-k-frequent-elements/description/

 read this editorial as well
https://leetcode.com/problems/top-k-frequent-elements/editorial/

*/


#include <bits/stdc++.h>
using namespace std;

#define loop(i,a,b)     for(int i=(a); i<(b); i++)
#define all(x)          (x).begin(), (x).end()
#define pii pair<int,int>

void setupIO() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

// priority_queue approach

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
           unordered_map < int,int> freq;

           for( int el : nums )   // O(N)
           freq[el]++;

           // mean heap of k size
       

          priority_queue < pii, vector <pii> , greater<pii>>heap;   // mean heap

           for( auto [el , f] : freq){

               heap.push({f,el});
               if( heap.size() > k )
               heap.pop();

           }
            
            // now form your answer

            vector < int > ans;

            while( !heap.empty() ){      // KlogK
                  ans.push_back( heap.top().second );
                  heap.pop();
            }

        return ans;
    }
};


/*


`idea`->

  keep mean heap of k size.
  keep inserting el untill size == k
  size > k , the pop => min freq el will de deleted
  atlast only k el fo highest freq will remain in my priority_queue


  time : o(N)[map]+ Klog(K) + Klog(K)



*/


// quick-select apporach



















//  write `Bucket sort `approach


int main(int argc, char const *argv[]) { setupIO();



    return 0;
}