/*

https://leetcode.com/problems/non-overlapping-intervals/?envType=study-plan-v2&envId=leetcode-75

concpet : greedy ie optimal choices at each step




*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
          int N = intervals.size();


          sort( intervals.begin(),intervals.end(), [&]( const vector<int>&a, const vector<int>&b ){
            // end times are equal, then inncreasing order of starttime

             if( a[1] == b[1]) return a[0] < b[0];

            // on the basis of end time and in increaseing order
              return   a[1] < b[1];
          });

           int cnt = 0; 
           const int inf = INT_MAX;
           int prev = -inf;

           for( int i = 0;i < N; i++){
             if( intervals[i][0] >= prev ){
                   cnt++;
                   prev = intervals[i][1];
             }
           }
        
         return N  - cnt;
    }
};

 /* 
    # Given 
      - intervals array = > intervals[i]  = {st,end}


    # Return 
      - min. intevals need to make the rest intervals no-overlapping  


    # solution 
       - condition for non-overlap
          prevEndTime <= CurrStartTime

        *[imp]->whilch will be best\
              |-> sorting on the basis of startime or endtime

       * okay, sorting on the basis of endtime works here why it works\
                |-> 
               




 */

int main(int argc, char const *argv[]) { 



    return 0;
}