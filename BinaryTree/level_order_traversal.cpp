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
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 right(right) {}
 };
 


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

          /*
            time-> O(no of nodes in binary tree)
            space ->O( maxnodes in a levl)
          
          
          */

          

        queue<TreeNode*> q;
        if (root)
            q.push(root);

        vector<vector<int>> ans;

        while (!q.empty()) {

              

            int sz = q.size();

            vector<int> levEl; // each level elements

            for (int i = 0; i < sz; i++) {

                TreeNode* node = q.front();
                q.pop();

                levEl.push_back(node->val);

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            ans.push_back(levEl);
        }

        return ans;
    }
};

/*







*/

int main(int argc, char const *argv[]) { 


    return 0;
}