/*
 
https://leetcode.com/problems/subarrays-with-k-different-integers/description/?envType=problem-list-v2&envId=roduh55i


*/

#include <bits/stdc++.h>
using namespace std;

#define loop(i,a,b)     for(int i=(a); i<(b); i++)
#define all(x)          (x).begin(), (x).end()

class Solution {
public:
    int f( vector< int>&nums, int k, int N ){
       /*
           time : o(N)
           space : O(N)

       */



            int left = 0, ans = 0;

          unordered_map< int,int> mp;

         for( int right = 0; right < N; right++ ){
                 
                  mp[ nums[right] ]++;

                  while( !mp.empty() && mp.size() > k ){
                   
                        mp[ nums[left] ]-- ;
                    if( mp[ nums[left] ] == 0 ) mp.erase( nums[left] );

                    left++;

                  }
              
              ans += ( right - left + 1);
              
         }

         return ans;


    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
               int N = nums.size();
       return f( nums,k,N) - f( nums,k-1 , N );
        
    }
};

/*
  to find :  no of good sub-arrays

  given :

  `good subarray`: no of diff integer in that subarray is exactly k

    

  ` Intution and Approach` :->

    ans = no of sub-arrays with at most k distinct - no of subarrays with atmost (k-1) distinct 

         ie no (upto k distinct) -  no (less than k distinct)



*/

int main(int argc, char const *argv[]) { 



    return 0;
}