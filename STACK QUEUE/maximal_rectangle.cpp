/*


https://leetcode.com/problems/maximal-rectangle/

concept :  identification of histogram problem 
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largest_Area_Rectangle_in_Histogram( vector <int>&heights){

        // time : O(N^2)

             int N = heights.size();
          
          int res = 0;
          for( int i = 0; i < N; i++){

            int left = i - 1, right = i + 1;

             while( left >= 0 && heights[left] >= heights[i] ) left--;
             while( right < N && heights[ right] >= heights[i] ) right++;

             int leftWidth = ( (i - 1) - left );
             int rightWidth = ( right - ( i+ 1));

             int width = leftWidth + rightWidth + 1;

             res = max( res, heights[i] * width);
                  
             

          }



      return res;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {

         int M = matrix.size(), N = matrix[0].size();

            vector <int>colSum( N, 0);

            int ans = 0;

            for( int i = 0; i < M; i++ ){
                 for( int j = 0; j < N; j++ ){
                  //  colSum[j] += ( matrix[i][j] -'0' ==  ? 1 : 0);
                    if( matrix[i][j] == '1'){
                        colSum[j] += (matrix[i][j] -'0');
                    }else{
                         colSum[j] = 0;

                    }
                 }
                 ans = max( ans, largest_Area_Rectangle_in_Histogram( colSum) );

            }

            return ans;
        
    }
};


// time complexity : O( N ^ 3)
// can be optimized in O(N^2) by writing `largest_Area_Rectangle_in_Histogram() ` this function
// in o(N) by using monotonic stack

int main(){
    return 0;
}