/*

https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/?envType=problem-list-v2&envId=ogtdbr37



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



class Solution {
public:
  int M, N;
  vector<vector<int>> matrix;
  vector< vector<int>>dp;
 vector< vector<int>>dir = { {1,0}, {0,1}, {-1,0}, {0,-1} }; 
    bool IsLeaf( int i, int j){
           
            bool ans = false;

            if( i + 1 < M)
          ans |=  (matrix[i][j] < matrix[i+1][j] ); 
           if( i - 1 >= 0)
          ans |=  (matrix[i][j] < matrix[i-1][j] );  
           if( j + 1 < N)
          ans |=  (matrix[i][j] < matrix[i][j + 1] );
           if( j - 1 >= 0)
          ans |= ( matrix[i][j] < matrix[i][j-1]);     

        return !ans; 
        
    }
    bool IsValid( int i,int j){

       return ( i >= 0 && j >= 0 && i < M && j < N);
    }
    int f( int i, int j){
        
            if( i < 0 ||j < 0 || i >= M || j >=N || IsLeaf(i,j)) return 1;

              
               int ans = 1;

               if( dp[i][j] != -1 ) return dp[i][j];

            for( auto x : dir ){
                int nx = i + x[0], ny = j + x[1];
                if( IsValid(nx,ny) && matrix[i][j] < matrix[nx][ny] )
                 ans = max( ans, 1 + f( nx,ny));   
            }





        return  dp[i][j] = ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
             this->matrix = matrix;
             this->M = matrix.size();
             this->N = matrix[0].size();

            dp.assign(M+1, vector<int>(N+1, -1));
                  int ans = 0;
            for( int i = 0; i < M; i++){
                 for(int j = 0; j < N; j++){
                  ans = max( ans, f(i,j));
                 }
            }

            return ans;
    }
};
int main(int argc, char const *argv[]) { setupIO();



    return 0;
}