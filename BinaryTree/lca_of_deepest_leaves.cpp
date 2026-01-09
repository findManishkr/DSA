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

// solution - 1
class Solution1 {
public:

    int Level( TreeNode * root){
        if( !root) return 0;
        return 1 + max( Level(root->left), Level(root->right));
    }
    void f(TreeNode* node, TreeNode* par, map< TreeNode*, TreeNode*>&parent, vector<TreeNode*>&deepleaves, int currLev, int DeepLev ){
             if( !node ) return ;

             parent[node] = par;
             if( currLev == DeepLev)
             deepleaves.push_back( node);

             f(node->left, node, parent, deepleaves, currLev+1, DeepLev);
             f(node->right, node, parent, deepleaves,currLev+1, DeepLev);

    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {

         map< TreeNode*, TreeNode*>parent;
         vector<TreeNode*>deepleaves;
         int DeepLev = Level(root) - 1;

         f(root,NULL, parent,deepleaves,0,DeepLev);

         // now find lca of all the deepest leaves

         while( deepleaves.size() > 1 ){

                set < TreeNode*>lca;

                for( auto node : deepleaves)
                lca.insert( parent[node]);

                deepleaves.assign( lca.begin(), lca.end()); 
               
         }


        return deepleaves[0];
    }
};

/*

 # problem paraphrasing
   - to find lca of all the `deepest` nodes

 # solution
   -  i wiil run dfs and will keep all the deepest nodes in a vector\
            |-> in vector, i will keep replacing all el with its parents, untill size becomes 1\
                 |-> last el will be the lca and my answer also

 # Edge case 
   - when there in only one deepest leave , this deepest leave is my answer


 # complexity
     - time : O(Nlog(N))   \
          |-> dfs(O(N)) +  map insertion :-> NLog(N)
      - space : O(N)                      







*/

int main(int argc, char const *argv[]) { 



    return 0;
}