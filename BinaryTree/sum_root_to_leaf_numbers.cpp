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
    void f( TreeNode* root, string &s, vector<string>&ans ){
              if( !root ) return ;

              s += to_string( root->val);

              if( !root->left && !root->right ){
                   ans.push_back(s);
              } 

              f(root->left, s,  ans);
              f(root->right, s, ans);

             s.pop_back();         // backtracking step



    }
    int sumNumbers(TreeNode* root) {
        
           string res = "";
           vector< string > ans;

          f(root, res, ans);

          int sum = 0;

          for( string &str : ans)
            sum += stoi( str);
            

          return sum;
    }
};

  // Approach 2

 bool IsLeaf( TreeNode* node ){
    return (!node->left && !node->right);
   }

    int f( TreeNode* root , int currsum ){
            if( !root ) return 0;

            currsum = currsum * 10 + root->val;

            if(  IsLeaf(root) ) return currsum;

       return ( f(root->left,currsum) + f(root->right,currsum));
    }
    int sumNumbers(TreeNode* root) {
        
        return f(root, 0);
    }
int main(int argc, char const *argv[]) { setupIO();



    return 0;
}