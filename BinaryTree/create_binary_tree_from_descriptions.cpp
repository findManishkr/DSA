#include <bits/stdc++.h>
using namespace std;

/*
//  Definition for a binary tree node ( by creating class).
  

  class TreeNode{
      public:

      int val;
      TreeNode* left ;
      TreeNode* right;

      // constructor 
       
      TreeNode( ){
          this->val = 0;
         this->left = NULL;
         this->right = NULL;
      }
       
      TreeNode(int val ){
         this->val = val;
         this->left = NULL;
         this->right = NULL;
      }

       TreeNode(int val, TreeNode* left, TreeNode* right ){
         this->val = val;
         this->left = left;
         this->right = right;
      }


  };

  */
 
  //  Definition for a binary tree node ( by creating struct).

  struct TreeNode{
      int val;
      TreeNode* left;
      TreeNode* right;

      // now 3 constructors
      TreeNode() : val(0), left(NULL), right(NULL) {}
      TreeNode( int x) : val(x), left(NULL), right(NULL) {}
      TreeNode( int x, TreeNode* left, TreeNode* right) : val(x), left( left), right(right) {}


  };



  
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        
          unordered_map< int, TreeNode*> nodes;
          unordered_set<int>seen;   // all child nodes

           for( auto& d : descriptions ){
               int parent = d[0], child = d[1], Isleft = d[2];
                 
                 // create new node for parent if it is already not created

                 if( !nodes.count( parent ) )
                    nodes[parent] = new TreeNode( parent);

                 // create child node if it is not already created

                 if( !nodes.count( child) )
                   nodes[child]  = new TreeNode( child);

                   // now make connection

                   if( Isleft == 1)
                      nodes[parent]->left = nodes[child];
                   else
                      nodes[ parent]->right = nodes[ child];

                   // now mark the child node 

                   seen.insert( child);   


           }

            // now , find the root node , root node is the node that never appears as child
                TreeNode* root = NULL;
             for( auto x : descriptions ){
                  if( !seen.count( x[0] ) ){
                       root = nodes[ x[0]];
                  }
             }

             return root;
    }
};

int main(){









    return 0;
}