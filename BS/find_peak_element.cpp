/*

https://leetcode.com/problems/find-peak-element/description/


concept : observation how binary search can be applied 


*/


#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findPeakElement(vector<int>& nums) {
            int N = nums.size();

            if( N == 1 ) return 0;
            

            int left = 0 ;
            int right = N - 1;

            while( right - left > 1 ){

              int mid =  ( right - left ) /2 + left ;

              if( nums[ mid ] > nums[ mid + 1] ){       // slope is falling , peak lies in left;
                  right = mid;

              }else {        // slope ing rising , peak lies in right
                  left = mid;
              }


            }
            
            return ( nums[left] > nums[ right] ) ? left : right;
                }
};


int main(){




    return 0;
}