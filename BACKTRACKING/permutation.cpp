/*
https://leetcode.com/problems/permutations/?envType=study-plan-v2&envId=top-100-liked



*/

#include <bits/stdc++.h>
using namespace std;

#define loop(i,a,b)     for(int i=(a); i<(b); i++)
#define all(x)          (x).begin(), (x).end()

class Solution {
public:

    void f( int idx, vector<int>&nums, vector<vector<int>>&ans, int N){
              if( idx == N ){      // base case  [ idx == N -1] will also work here 
                   ans.push_back(nums);
                   return ;
              }

             for( int i = idx; i < N ; i++){
                   swap(nums[idx], nums[i] );
                    f(idx+1, nums, ans, N);
                   swap(nums[idx], nums[i] );      // backtracking step                  // revert the changes, while backtracking
             }

    }
    vector<vector<int>> permute(vector<int>& nums) {
                int N = nums.size();
               vector<vector<int>>ans;

               f(0, nums ,ans ,N );

               return ans;
    }
};

int main(int argc, char const *argv[]) { 



    return 0;
}

/*

Short explanation:
- Generates all permutations using backtracking with in-place swaps: for each index `idx`, swap every element `i>=idx` into position `idx` and recurse.
- Base case: when `idx == N`, push the current `nums` as a permutation into `ans`.
- Complexity: Time O(N * N!) (N! permutations, each takes O(N) to copy), Space O(N) recursion depth plus output size.
*/