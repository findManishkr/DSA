/*

https://leetcode.com/problems/search-a-2d-matrix/

concept : simple binary search



*/

#include <bits/stdc++.h>
using namespace std;

// solution : 1

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int M = matrix.size(), N = matrix[0].size();

        int lo = 0, hi = M * N - 1;

        while( hi - lo >= 0 ){

            int mi = lo + ( hi - lo) /2;

             int row = mi / N, col = mi % N;

             if ( matrix[ row ][ col ] == target ) return true;
             else if( matrix[ row ][ col ] < target ) lo = mi + 1;
             else hi = mi - 1;

        }

      return false;
    }
};


/*

/*
Observation:

1. If we conceptually flatten the 2D matrix into a 1D sorted array 
   (by placing all rows one after another), the elements remain sorted 
   because each row is sorted and the first element of each row is greater 
   than the last element of the previous row.

2. In this flattened form:
   - The first element has index 0
   - The last element has index M*N - 1

3. We can perform a single binary search on this "virtual" 1D array.
   - mid index → corresponds to: 
       row = mid / N       (integer division)
       col = mid % N       (remainder)

4. This allows us to access the correct matrix element from the 1D index
   without actually creating a separate 1D array.


Time complexity: O(log(M*N)) = O(log M + log N)
Space complexity: O(1)
*/

 


// solution - 2;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int M  = matrix.size();
        int N = matrix[0].size();

        vector < int > arr(M);
        for( int i = 0; i < M; i++)
          arr[i] = matrix[i][0];

          int lo = 0, hi = M -1;

          while( lo <= hi ){

            int mi = lo + ( hi - lo) /2;

            if( arr[ mi] <= target  ){
           
              auto it = lower_bound( matrix[mi].begin(), matrix[mi].end(), target);
              
              if( it != matrix[mi].end() &&  *it == target ) return true;
              
              
              lo = mi + 1;
            

            }else{
                hi = mi -1;
            }

          }

          return false;
    }
};

/*

// observation :

1. all rows are sorted and first column is also sorted.
2. if first integer of  any row is greater than target , then all the rows from that row will not contain target, why ?
 because that  it self starts form a number which is greater than target, and that row is sorted;


// time complexity :


// time complexity :

// Step 1: Binary search on the first column to find the possible row(s) 
// → O(log M) where M is the number of rows.

// Step 2: For each candidate row, perform a binary search using lower_bound 
// → O(log N) where N is the number of columns.

// In the worst case, binary search on rows picks one row, 
// and we do one binary search on that row's elements.

// Overall time complexity = O(log M + log N) ie  total time = step 1 + step 2

  

*/



int main(){



    return 0;
}