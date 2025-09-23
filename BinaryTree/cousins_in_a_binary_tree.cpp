/*

https://leetcode.com/problems/cousins-in-binary-tree/

*/



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
    
     void f( TreeNode*root, int lev, TreeNode*par, vector<int>&depth, vector<int>&parent ){
            if( !root ) return ;

            depth[ root->val ] = lev;
            
           parent[root->val] =  !par ? -1 : par->val;


           f( root->left, lev+ 1, root, depth, parent);
           f( root->right, lev + 1, root, depth, parent);
           

          
        
          

     }
    bool isCousins(TreeNode* root, int x, int y) {
            
            vector <int > depth(101 , 0);
            vector<int>parent(101, -1);
            f(root, 0, NULL,depth,parent);

           

            return depth[ x] == depth[y] && parent[x] != parent[y] ;
    }
};


/*
  `Intuition`:->

     Two nodes in a binary tree are cousins if they are at the same depth/level but have      different parents. 
     So, we just need to check the depth of both nodes and their parents.

   `Approach`:->

     Use DFS (or BFS) to traverse the tree. While traversing, store:
       1. The depth of each node.
       2. The parent of each node.
     After traversal, if both nodes have the same depth but different parents, return true; else return false.

   `Algorithm`:->

     1. Initialize two arrays:
        - `depth[101]` to store the depth of each node.
        - `parent[101]` to store the parent of each node.
     2. Start DFS from the root:
        - For each node, store its depth and parent.
        - Recurse to left and right children with depth+1.
     3. After DFS, check:
        - If `depth[x] == depth[y]` and `parent[x] != parent[y]`, return true.
        - Else, return false.
*/


int main(int argc, char const *argv[]) { 



    return 0;
}