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
// multiset implemntation


class Solution {
public:

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
                   /*
                     time complexity : 
                              every time an el is inserted untill multiset size >= K

                            log(1) + log(2) + log(3).........+ log(k)   = log(1*2*3*..k) = log(k!) ~ klog(k)


                            after\
                             |->  ms.size() >= k
                                  deletion -> (N-K)log(k)
                                  insertion-> (N-k)log(k)
                        
                          total time complexity =  klogk + N-klog(k) = ( k + N - K) logK  = O(NlogK)


                          further optimize it to O(N) using monotonic deque



                   */ 

              int N = nums.size();


               vector< int> ans;
              multiset< int, greater<int> >ms;

            for( int i = 0; i < N; i++){
             
                   ms.insert(nums[i]);

                  if( i >= k ){
                     ms.erase( ms.find( nums[i-k] ) );
                  }

                  if( i >= k - 1)
                  ans.push_back( *ms.begin());
     
            }

       return ans;
    }
};

// write heap implementation





// write dq solution

int main(int argc, char const *argv[]) { setupIO();



    return 0;
}