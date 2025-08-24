/*

 https://leetcode.com/problems/maximal-square/


'1' → usable, contributes to squares.

'0' → unusable, forces that DP/recursion state to 0.

*/


#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int M, N;
    vector < vector <char>>grid;
    int dp[305][305];
    int f( int i , int j , int &maxLen){
         if( i >= M || j >= N) return 0;

           if( dp[i][j] != -1) return dp[i][j];

           int right = f( i, j + 1, maxLen);
           int down = f( i+ 1, j , maxLen);
           int diagonal = f( i+ 1, j + 1, maxLen);

           int ans = 0;

           if( grid[i][j] == '1'){
           ans =  1 + min( {right, down, diagonal});
             maxLen = max( maxLen , ans);   // i'm taking maximum because, my answer my be zero also in this if scope also
           }
           else {
             ans = 0;
           }

           return  dp[i][j] =  ans;
          
    }
    int fbu(  ){

          vector< vector <int>>tab(M+1, vector <int> (N+1,0));
             int maxLen = 0;
          for( int i = M -1; i >= 0; i--){
            for( int j = N -1; j >= 0; j--){
                if(  grid[i][j] == '1'){
                     tab[i][j] = 1 + min( { tab[i][j+1], tab[i+1][j], tab[i+1][j+1] });
                      maxLen = max( maxLen,  tab[i][j] );
                }else{

                    tab[i][j] = 0;
                }
            }
          }


      return maxLen ;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
           M = matrix.size();
           N = matrix[0].size();
           grid = matrix;

           /*
            memoization  part 

           int maxLen = 0;
            memset(dp, -1, sizeof(dp));

           f( 0, 0, maxLen);

           return ( maxLen * maxLen);

           */

           // bottom up part 
            
            int maxLen = fbu();
         return ( maxLen * maxLen) ;
    }
};

int main(){
    return 0;
}