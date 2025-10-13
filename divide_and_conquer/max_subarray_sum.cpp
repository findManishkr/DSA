/*

https://leetcode.com/problems/maximum-subarray/

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int N;
    vector<int>nums;
    const int inf = INT_MAX;
    int ff( int left, int mid, int right){

          int leftMaxSuffixSum = -inf;
          int currsum = 0;

          for( int i = mid; i>= left; i--){
                 currsum += nums[i];
                leftMaxSuffixSum = max(leftMaxSuffixSum, currsum);
          }

          int rightMaxPrefixSum = -inf;
          currsum = 0;

          for( int i = mid + 1; i <= right; i++){
              currsum += nums[i];
              rightMaxPrefixSum = max(rightMaxPrefixSum, currsum);
          }
         

        return leftMaxSuffixSum + rightMaxPrefixSum;
    }
    int f( int left, int right  ){

        // base case 
        if( left == right) return nums[left];


       // divide ops

        int mid = (left + ((right-left) >> 1));

     int   leftMaxSubArray =   f(left,mid);
     int    rightMaxSubArray = f( mid+1, right);
     int    maxCrossingSum =   ff(left, mid, right);




        // conquer ops



        return max( {leftMaxSubArray, rightMaxSubArray ,  maxCrossingSum} );
    }
    int maxSubArray(vector<int>& nums) {
             this->N = nums.size();
             this->nums = nums;


             return f(0,N-1);
    }
};
/*
  time : O( NlogN )
  space : O(LogN) max recursive depth

*/



/*


1-> ps
2-> constraint;
3-> ds, a
4->implemnt
5->testing &debugging
6-> explanations and followup
 

#APPROACH
 

## -> Divide and Conquer Intuition

We can think recursively:
Split the array into two halves.
The maximum subarray sum can be:
Entirely in the left half
Entirely in the right half
Crossing the middle (spanning both halves)
Then, take the maximum of the three.



*/

int main(int argc, char const *argv[]) { 



    return 0;
}