/*

 https://leetcode.com/problems/maximum-erasure-value/description/?envType=daily-question&envId=2025-07-22


  concept : variable size sliding window
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& arr) {
         /*
         
           time : O(N)
           space : O(N)  due to using set 
         
         */

          int N = arr.size();

          int left = 0;
          int res = 0, currSum = 0;

          unordered_set < int > seen;

          for( int right = 0;  right < N; right++){
                  
                // duplicate is found , make the window unique again by removing duplicates
                  while(  seen.count( arr[ right] )  ){
                      
                       currSum -= arr[ left ];
                       seen.erase( arr[ left] );

                       left++;

                  }
                  

                  // if duplicate not found 

                  currSum += arr[ right ];
                  seen.insert( arr[ right ]);
                  res = max( res,  currSum);



          }

          return res;
    }
};

int main(){


    return 0;
}