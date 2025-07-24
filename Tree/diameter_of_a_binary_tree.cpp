
#include <bits/stdc++.h>
using namespace std;

void setupIO() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif
}
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 
class Solution {
public:
    int diameter = 0;
 
    int f( TreeNode* root ){
        if( !root ) return 0;
          
        int lstDia = f( root->left);
        int rstDia = f( root->right);

        diameter = max( diameter , lstDia + rstDia);  

        return  1 + max( lstDia , rstDia);
    }
    int diameterOfBinaryTree(TreeNode* root) {
           f(root);

           
           return diameter ;
    }
};
int main() {
    setupIO();

   

    return 0;
}
