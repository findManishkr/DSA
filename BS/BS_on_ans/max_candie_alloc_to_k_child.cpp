/*
https://leetcode.com/problems/maximum-candies-allocated-to-k-children/

concept : classic maximisation problem of bs on answer

*/


#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
   bool f( vector < int>&candies, ll k, int mi){
                int N = candies.size();
            ll cnt = 0;
            for( int i = 0; i <  N ; i++)
                cnt += ( candies[i] /mi ); 
            
       return cnt >= k;
   }
    int maximumCandies(vector<int>& candies, long long k) {
           
           int lo = 1, hi = *max_element( candies.begin(), candies.end());
                int ans = 0;     // at edge case conditions
            while( hi - lo >= 0){
              
              int mi = lo + (hi - lo) /2;

              if( f( candies, k, mi ) ){
                   ans = mi;
                   lo = mi + 1;
              }else{
                  hi = mi - 1;
              }

            }

            return ans;
    }
};

// ` to find : max no of candies each child can be allocated`

// `observations`
// 1. answer lies b/w rang  1 to max( arr[i])
// 2. this made me to think in search spaces
// classic problem of maximation problem of binary search one the answer


// complexity 

    //       O( N Log (max[arr[i]]));
    

int main(){


    return 0;
}