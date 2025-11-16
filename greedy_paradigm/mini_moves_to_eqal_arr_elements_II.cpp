/*

https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/submissions/1800256470/


  concept :  `use of median`
*/

#include <bits/stdc++.h>
using namespace std;

#define loop(i,a,b)     for(int i=(a); i<(b); i++)
#define all(x)          (x).begin(), (x).end()

class Solution {
public:
    int f( vector<int>&nums, int median){

        int ans = 0;
        for( int i = 0; i < nums.size(); i++)
        ans += abs(nums[i] - median);

        return ans;
    }
    int minMoves2(vector<int>& nums) {
         int N = nums.size();
        sort( nums.begin(),nums.end());

        int ans = (N % 2) ? f(nums,nums[N/2]) :min( f(nums,nums[N/2]),f(nums,nums[N/2-1]) );

       return ans;
    }
};

int main(int argc, char const *argv[]) { 



    return 0;
}