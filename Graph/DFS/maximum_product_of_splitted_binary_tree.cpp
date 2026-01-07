/*
https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/description/?envType=daily-question&envId=2026-01-07



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

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


#define ll long long
class Solution {
public:
    const int mod = 1e9 + 7;
    ll f( TreeNode* root, ll &res, ll totalsum){
            if( !root ) return 0;

            ll subtreesum = root->val + f( root->left, res, totalsum) + f( root->right, res, totalsum);

            res = max( res, subtreesum * ( totalsum - subtreesum) );


            return subtreesum;
    }
    ll ff( TreeNode* root){
            if( !root) return 0;
        return root->val+ ff(root->left) + ff(root->right);
    }
    int maxProduct(TreeNode* root) {
         
          ll totalsum = ff(root);

          ll res = 0;
          f(root, res, totalsum);

         return int( res % mod);
    }
};

/*
If we know the sum of a subtree, the answer is max( (total_sum - subtree_sum) * subtree_sum) in each node.

*/


int main(int argc, char const *argv[]) { setupIO();



    return 0;
}