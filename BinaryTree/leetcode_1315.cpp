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
     map < TreeNode*, TreeNode*> parent;
      void f( TreeNode* root, TreeNode* par ){
              if( !root ) return ;

             parent[root] = par;

             f(root->left, root);
             f(root->right, root); 


      }

    void ff( TreeNode* root, int &res){
         if( !root) return ;

                 
                     TreeNode* p  = parent[root];
                     
                     if( p ){  // parent exists
                      TreeNode* gp = parent[p];
                      if( gp && !(gp->val % 2 )) res += root->val;
                     }

               ff(root->left,res);
               ff( root->right,res);

     
    }
    int sumEvenGrandparent(TreeNode* root) {

            f(root,NULL);

            int res = 0;
         ff( root,res);
        return   res;
    }
};

int main(int argc, char const *argv[]) { setupIO();



    return 0;
}