/*

https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

concept : `divide and conquer algorithm`

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


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* f( int i , int j ,vector<int>&nums){
               // base case
                if( i > j) return NULL; 
                 if( i == j) {
                      TreeNode *last = new TreeNode( nums[j]);
                      return last;
                 }

           int mid = ( i + j ) >> 1;

           TreeNode* root = new TreeNode( nums[mid]);
              
              // divide ops

           TreeNode* lst  = f(i, mid-1, nums);
           TreeNode* rst  = f(mid+1, j, nums);

           // conquer ops
           root->left = lst;
           root->right = rst;

           return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
          int N= nums.size();


        return f(0, N -1, nums);
    }
};

 /*
 
  # GIVEN 
    -sorted array
    
  # RETURN
   - height balanced bst construction with the help of array



   # Solution
    - my intution goes towards `divide and conquery ops`
    - f( i,j, arr) -> returns the `req. height balanced bst`
 
          int mid = ( i + j )/ 2;
          TreeNode *root = new TreeNode( nums[mid]);

          root->left  = f( i, mid -1, arr);
          root->right = f(mid+1, j, arrr);


          // base case
           if( i > j ) return NULL;  // no tree
           if( i == j) return TreeNode(nums[i])
 
 
 */

int main(int argc, char const *argv[]) { setupIO();



    return 0;
}