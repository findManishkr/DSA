/*


https://leetcode.com/problems/matrix-block-sum/

*/
#include <bits/stdc++.h>
using namespace std;

#define loop(i,a,b)     for(int i=(a); i<(b); i++)
#define all(x)          (x).begin(), (x).end()

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
             
               int M = mat.size();
               int N= mat[0].size();

               vector< vector<int>>pf( M + 1, vector<int>(N+1,0));

               for( int i = 1 ;  i <= M ; i++){
                 for( int j = 1; j <= N; j++ ){

                  pf[i][j] = mat[i-1][j-1] + pf[i-1][j] + pf[i][j-1] - pf[i-1][j-1];
                 }
               }

               vector< vector<int>> answer( M, vector<int>(N,0));

               for( int i = 0; i < M; i++){
                 for( int j = 0;j < N; j++){

                     int r1 = max(0, i - k);
                     int r2 = min( M -1, i + k);
                     int c1 = max( 0, j - k);
                     int c2 = min( N -1, j + k);

                    r1++, r2++, c1++,c2++;  // to avoid out of bound error

                    answer[i][j] =  pf[r2][c2] - pf[r2][c1-1]-pf[r1-1][c2] + pf[r1-1][c1-1];


                 }
               }


         return answer;        
    }
};


int main(int argc, char const *argv[]) { 


    return 0;
}