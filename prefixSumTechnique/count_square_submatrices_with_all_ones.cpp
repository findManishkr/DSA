/*

https://leetcode.com/problems/count-square-submatrices-with-all-ones/description/git 

*/





#include <bits/stdc++.h>
using namespace std;

#define loop(i,a,b)     for(int i=(a); i<(b); i++)
#define all(x)          (x).begin(), (x).end()

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
            int M    = matrix.size();
            int N = matrix[0].size();

            // build prefix sum

             vector< vector< int >>pf(M+1, vector<int>(N+1,0));
              for(int i  = 1; i <= M; i++){
                for( int j = 1; j <= N; j++){
                      pf[i][j] = matrix[i-1][j-1] + pf[i-1][j] + pf[i][j-1] - pf[i-1][j-1];

                }
              } 
            
              int res = 0;

              for( int dim = 1; dim <= min(M,N); dim++){

                  for( int  i = 0;  i + dim -1  < M; i++){

                       for( int j = 0; j + dim -1  < N; j++){

                           int r1 = i, c1 = j;
                           int r2 = i + dim -1, c2 = j + dim - 1;

                             r1++,r2++,c1++,c2++;  // made 1 based indexing
                             

                            int subMatSum = pf[r2][c2] - pf[r1-1][c2] - pf[r2][c1-1] + pf[r1-1][c1-1]; 

                            if( subMatSum == dim * dim ) res++;
                       }
                  }
              }

              return res;
    }
};

int main(int argc, char const *argv[]) { 



    return 0;
}