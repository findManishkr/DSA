/*

https://leetcode.com/problems/range-sum-query-2d-immutable/


to build up prefix sum 

 rec rel :

  pf(i,j) = arr(i,j) + pf(i-1,j) + pf(i, j-1) - pf(i-1,j-1)



  to find sum of range [(r1,c1), (r2,c2) ]
  
   res =   pf(r2,c2) - pf(r2, c1 -1) - pf(r1 -1, c2) + pf( r1-1, c1 -1)

*/
 
#include <bits/stdc++.h>
using namespace std;


class NumMatrix {
public:
    int M , N;
    vector< vector<int>>pf;
    NumMatrix(vector<vector<int>>& matrix) {

                M = matrix.size();
                N = matrix[0].size();
                pf.resize( M + 1, vector<int>(N+ 1,0));
                
                for( int i = 1; i <= M; i++){
                     for( int j = 1; j <= N; j++ ){
                        pf[i][j] = matrix[i-1][j-1] + pf[i-1][j] + pf[i][j-1] - pf[i-1][j-1];
                     }
                }


    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {

          int res = pf[row2+1][col2+1] - pf[row2 +1][col1 ] - pf[ row1 ][col2 + 1]   + pf[row1 ][col1];

          return res; 
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

int main(int argc, char const *argv[]) { 



    return 0;
}