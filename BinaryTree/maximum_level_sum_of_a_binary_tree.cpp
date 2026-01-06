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

 // approach -1 dfs
class Solution {
public:
    int level( TreeNode* root){
         if( !root ) return 0;
         return 1 + max( level(root->left), level(root->right));
    }
    void f( TreeNode *root, int currLev,vector<int>&ans){
           if( !root) return ;

           ans[currLev] += root->val;

           f( root->left, currLev+1, ans);
           f( root->right,currLev+1, ans);


    }
    int maxLevelSum(TreeNode* root) {
              
        int Level = level(root);

        vector<int>ans(Level+1, 0);
        const int inf = 1e9 + 7;
        ans[0] = -inf;

        f(root,1, ans);

             for( int el : ans){
                  cout << el <<' ';
             }
        int idx   = max_element( ans.begin(),ans.end()) - ans.begin();
          

      return idx;
    }
};

 /*

   lev, sum
   1 - {1}
   2 - {7,0}
   3 - {7,-8}

     vector<int>sum


 */

 // Approach 2 : bfs

 class Solution2 {
public:
    int maxLevelSum(TreeNode* root) {

           queue < TreeNode*> q;
           q.push(root);

             int currLev = 0;
             const int inf = INT_MAX;
             int maxisum = -inf;
             int maxsumlev = -1;
          

            while( !q.empty() ){

                 int sz = q.size();
                 currLev++;

                 int sum = 0;

                 for( int i = 0; i < sz; i++){

                      TreeNode* node = q.front(); q.pop();
                      sum += node->val;

                      if( node->left)
                      q.push(node->left);
                      if( node->right)
                      q.push(node->right);

                 }

                   if( maxisum < sum ){
                        maxisum = sum ;
                        maxsumlev = currLev;
                   }

            } 


            
        
        return maxsumlev;
    }
};

 

int main(int argc, char const *argv[]) { setupIO();



    return 0;
}