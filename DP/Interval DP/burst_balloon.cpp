/*

https://leetcode.com/problems/burst-balloons/description/?envType=problem-list-v2&envId=55aj8s16

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

 int fbu( vector<int>& arr ){
         /*
            to find the answer of bigger subarray, you will have to first find the answers of smaller subarrays

         */

           int N = arr.size();

            // answer of arr of len = 1 and len = 2 is zero

            vector< vector<int>>dp(N+1, vector <int> (N+1,0));

            for( int len = 3; len <= N; len++){
              
               for( int i = 0; i <= ( i + len -1); i++ ){
                     int j = i + len -1;
                        dp[i][j] = -inf;
                      for( int k = i + 1; k <= j -1; k++){
                        dp[i][j]  = max( dp[i][j], arr[i] *arr[k]* arr[j] + dp[i][k] + dp[k][j]);
                      }

               }

            }




        return dp[0][N-1];
     }

int main(int argc, char const *argv[]) { setupIO();



    return 0;
}