#include <bits/stdc++.h>
using namespace std;

#define loop(i,a,b)     for(int i=(a); i<(b); i++)
#define all(x)          (x).begin(), (x).end()



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
   bool IsMirror( TreeNode* p , TreeNode* q){

        // base case 
         if( !p && !q) return true;    // if both lst and rst are null , return true
         if( !p || !q) return false;  // 

         
         bool ans = (p->val == q->val) && IsMirror(p->left, q->right) &&  IsMirror(p->right, q->left);
            
        return ans;
   }
    bool isSymmetric(TreeNode* root) {
               
       return IsMirror( root->left, root->right);    
    }

};


/*

`intuition`:->

 -  A binary tree is `symmetric ` iff it is mirror of itself , arount its center\
         |-> its left subtree must be the mirror image of its right subtree

 -   But what makes two tree mirror images ?

     1. root value of both trees must be equal
     2. left child of first tree == right child of second tree
     3. right child of first tree == right child of first tree
              

  
*/
  

int main(int argc, char const *argv[]) { 


    return 0;
}