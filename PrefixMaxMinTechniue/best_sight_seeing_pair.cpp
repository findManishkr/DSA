/*

https://leetcode.com/problems/best-sightseeing-pair/submissions/1813942822/


*/

#include <bits/stdc++.h>
using namespace std;

#define loop(i,a,b)     for(int i=(a); i<(b); i++)
#define all(x)          (x).begin(), (x).end()

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
            /*
            prefix min/maxi technique

            */

           int n = values.size();

          int res = 0;

          int maxi = values[0] + 0;

          for( int i = 1; i < n; i++){
             
              if( res  < ( maxi + values[i]-i) ){
                    res = maxi + values[i] -i ;
              }

               maxi = max( maxi,values[i] + i);

          }


          return res;
    }
};

int main(int argc, char const *argv[]) { 



    return 0;
}