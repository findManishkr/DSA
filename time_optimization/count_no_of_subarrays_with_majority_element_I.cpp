/*

https://leetcode.com/contest/biweekly-contest-169/problems/count-subarrays-with-majority-element-i/

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
    int countMajoritySubarrays(vector<int>& nums, int target) {

          int n = nums.size();

            int res = 0;
          for( int i = 0; i < n; i++ ){
                   int cnt = 0;

               for( int j = i ; j < n; j++){

                   cnt += ( nums[j] == target);

                   if( cnt > ((j-i + 1) >> 1))
                       res ++;
                   
               }
        
          }

        return res;
    }
};

int main(int argc, char const *argv[]) { setupIO();



    return 0;
}




/*


──────────────────────────────────────────────────────────────────────────────
 🧬Intuition
──────────────────────────────────────────────────────────────────────────────
A subarray has `target` as a strict majority when the target occurs
**more than half** of the subarray’s length.

So while expanding a window [i..j], we simply keep a running count of how many
times `target` appears. Whenever this count overtakes half the window size,
that subarray immediately qualifies.
──────────────────────────────────────────────────────────────────────────────


──────────────────────────────────────────────────────────────────────────────
 🧬Approach
──────────────────────────────────────────────────────────────────────────────
1. Fix a starting index i.
2. Extend the window to the right (j = i → n−1).
3. Increase `cnt` whenever nums[j] equals the target.
4. Check:  cnt > (j - i + 1) / 2   
   If true, subarray [i..j] has the target as a strict majority → count it.

Complexity:
- Time:  O(n²)  (brute force)
- Space: O(1)

For large inputs:
Convert array → (+1 if target, −1 otherwise) and count subarrays with positive sum.


──────────────────────────────────────────────────────────────────────────────


──────────────────────────────────────────────────────────────────────────────
              🧬     Code Explanation
──────────────────────────────────────────────────────────────────────────────
• int n = nums.size()  
    Stores array length.

• Outer loop (i):
    Selects the left boundary and resets `cnt = 0`.

• Inner loop (j):
    Expands the window.
    `cnt += (nums[j] == target);`  // adds 1 when nums[j] == target

• Majority check:
    cnt > ((j - i + 1) >> 1)
    Uses integer division by 2 to test “strict majority”.

• res:
    Counts all qualifying subarrays and is returned at the end.
──────────────────────────────────────────────────────────────────────────────

         🧬                                             🧬

*/
