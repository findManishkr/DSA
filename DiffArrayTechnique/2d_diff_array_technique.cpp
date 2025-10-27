/*

https://leetcode.com/problems/increment-submatrices-by-one/description/

*/


#include <bits/stdc++.h>
using namespace std;

#define loop(i,a,b)     for(int i=(a); i<(b); i++)
#define all(x)          (x).begin(), (x).end()


class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        
             vector< vector< int>>diff( n + 1, vector<int>(n+1,0));


              for( auto x : queries ){

                   int r1 = x[0], r2 = x[2];
                   int c1 = x[1], c2 = x[3];

                    diff[r1][c1]       += 1;
                    diff[r1][c2 + 1] -= 1;
                    diff[r2 +1][c1]  -= 1;
                    diff[r2+1][c2 + 1] += 1;

              }



            //   // take prefix sum , of difference array

               
                vector< vector<int>>ans(n, vector<int>(n,0) );
                ans[0][0] = diff[0][0];
                for( int i = 1; i < n; i++)  ans[i][0] = ans[i-1][0] + diff[i][0];
                for( int j = 1; j < n; j++)  ans[0][j] = ans[0][j-1] + diff[0][j];

                for( int i = 1; i < n; i++){
                    for( int j = 1; j < n; j++){
                        ans[i][j] = diff[i][j] + ans[i-1][j] + ans[i][j-1] - ans[i-1][j-1];
                    }
                }


           
               
               


              return ans;
    }
};

int main(int argc, char const *argv[]) {



    return 0;
}