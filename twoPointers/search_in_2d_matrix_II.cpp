/*

    https://leetcode.com/problems/search-a-2d-matrix-ii/description/

     concept :  two pointer 

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int M = matrix.size(), N = matrix[0].size();

        int i = 0;    //  from first row
        int j = matrix[0].size() - 1;    // from last column

        while ( i < M && j >= 0 ){

              if( matrix[i][j] == target ) return true;
              else if( matrix[i][j] < target ) i++;
              else j--;


        }

        return false;

    }
};


/*

 time : O ( M + N )

*/
int main(){
    return 0;
}