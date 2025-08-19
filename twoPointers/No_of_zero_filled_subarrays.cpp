/*

https://leetcode.com/problems/number-of-zero-filled-subarrays/

concept : two pointer + sliding window 

*/


#include <bits/stdc++.h>
using namespace std;

// one pass solution 1

#define ll long long 
class Solution {
public:


    long long zeroFilledSubarray(vector<int>& nums) {
        
        nums.push_back( -1 );
        ll ans = 0;
        ll cntzero = 0;
        for( int i = 0; i < nums.size(); i++){
          if( nums[i] == 0 ) cntzero++;
          else {
               ans += ( cntzero * (cntzero+ 1) * 1LL)/2;
               cntzero = 0;
          }
        }

        return ans;
    }
};


// solution - 2;

#define ll long long 
class Solution {
public:
      ll f( ll n){
        return ( n * (n +1))/2;
      }
    long long zeroFilledSubarray(vector<int>& nums) {
         int N = nums.size();

         int le = 0, ri = 0;
        ll ans = 0;
         while( le < N){

            while( ri < N && nums[ ri] == 0 ) ri++;

            if( ri - le == 0)
                 ri++, le++;
            else {
                 ans +=  f( ri - le);
                  le = ri;
                 
            }     
            

         }

         return ans;
    }
};


int main(){



    

    return 0;
}