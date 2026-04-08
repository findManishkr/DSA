/*


https://leetcode.com/problems/search-in-rotated-sorted-array/?envType=study-plan-v2&envId=top-100-liked


concept : binary search on rotated sorted arrays



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
    int search(vector<int>& nums, int target) {
        int N = nums.size();

        int low = 0, high = N - 1;

        while (low <= high) {   // correct

            int mid = (low + high) / 2;

            if (nums[mid] == target)    /// this is for mid ,
                return mid;
           else if (nums[low] <= nums[mid]) { // ie,  if left , part is sorted
                    // since all the arr values are distinct, 
                if (nums[low] <= target && target < nums[mid])    // equlity of mid is handled above   
                    high = mid - 1;
                else
                    low = mid + 1;

            } else  { // ie right part is sorted

                if (nums[mid] < target && target <= nums[high])  // equlity of mid is handled above   
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }    

            return -1;
        }
    };

    /*

     [ 4, 5, 6, 7, 0, 1, 2], target = 0;


      lo = 0, hi = 6;

      mid = 3;

      [4, 7] \
        4 < 3 < 7 | no
        lo = mid + 1  -. [ 4, 7]

         mid  = 5, 1

              [0] < [ 2]\
               |-> ( 0 < 1 < 2)
                  hi = mid - 1

                  [low = 4, high = 4;]



     # edge case
      
      [ 3, 1]  , target  = 1;



       [0, 1] -> mid = 0






    */

int main(int argc, char const *argv[]) { setupIO();



    return 0;
}