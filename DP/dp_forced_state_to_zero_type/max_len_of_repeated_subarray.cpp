/*

https://leetcode.com/problems/maximum-length-of-repeated-subarray/?envType=problem-list-v2&envId=rodluya6


concept : dp forced state to zero
*/

#include <bits/stdc++.h>
using namespace std;

#define loop(i,a,b)     for(int i=(a); i<(b); i++)
#define all(x)          (x).begin(), (x).end()

void setupIO() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}


class Solution {
public:
      int M, N;
      int dp[1001][1001];
      vector<int> nums1,nums2;
      const int inf = INT_MAX;
     int f( int i, int j, int& maxi ){

        if( i >= M || j >= N ) return 0;

                 
            if( dp[i][j] != -1) return dp[i][j];    


          if( nums1[i] == nums2[j] ){

             dp[i][j] = 1 + f(i+1,j+1,maxi);
             maxi = max( maxi, dp[i][j]); 

          }else{
              dp[i][j] = 0;

          }

            f(i+1,j,maxi);
              f(i,j+1,maxi);


       return dp[i][j];
     }
     int fbu(vector<int>& nums1, vector<int>& nums2){

           vector< vector< int >>dp(M+1, vector<int>(N+1,0));

               int maxSubArrLen = 0;

             for( int i = M -1; i >= 0; i--){
                for(int j = N -1; j >= 0; j--){
                      if(nums1[i] == nums2[j]){
                          dp[i][j] = 1 + dp[i+1][j+1];
                       maxSubArrLen = max( maxSubArrLen , dp[i][j]);
                      }else{
                         dp[i][j] = 0;  // dp forced state to zero
                      }
                }
             }

           return maxSubArrLen ;
     }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
            this->M = nums1.size();
            this->N = nums2.size();
            this->nums1 = nums1;
            this->nums2 = nums2;

            int maxi = 0;
             memset(dp, -1, sizeof(dp));
           // f(0,0,maxi);

           // return maxi;

          return fbu(nums1,nums2);
    }
};


/*
 
  dp forced state to zero : type problem


*/

int main(int argc, char const *argv[]) { setupIO();



    return 0;
}