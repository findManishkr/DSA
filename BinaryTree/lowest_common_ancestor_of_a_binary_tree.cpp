#include <bits/stdc++.h>
using namespace std;

#define loop(i,a,b)     for(int i=(a); i<(b); i++)
#define all(x)          (x).begin(), (x).end()


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
     bool f( TreeNode* root, vector<TreeNode*>&path,TreeNode* destNode){
           if( !root ) return false;

           path.push_back(root);

           if( root == destNode)
             return true;
           
           bool IsInLst = f(root->left, path, destNode);
           bool IsInRst = f(root->right, path, destNode);

           if( IsInLst || IsInRst ) return true;
           
           path.pop_back();

           return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
                vector<TreeNode*>path,path1 , path2;
                f( root, path1, p);
                f( root, path2 ,q);

                int i = 0;
                int sz1 = path1.size(), sz2 = path2.size();
                
                for( i = 0; i < min(sz1, sz2); i++){
                    if( path1[i] != path2[i])
                     break;
                }

                return path1[i-1];
    }
};
int main(int argc, char const *argv[]) {



    return 0;
}