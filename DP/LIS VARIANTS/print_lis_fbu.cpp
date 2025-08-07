/*
https://www.geeksforgeeks.org/problems/printing-longest-increasing-subsequence/1

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> getLIS(vector<int>& arr) {
        // Code here
          int N = arr.size();
              vector < int > dp(N, 1);
              vector < int > parent(N, -1);

              for( int i = 0; i < N; i++){
                for( int j = 0; j < i; j++){
                    if( arr[i] > arr[j] && dp[i] < 1 + dp[j]){
                           dp[i] = 1 + dp[j];
                           parent[i] = j;
                    }
                }
              }
              
              
              int lastIdx = -1, maxLen = 0;      //
              
              for( int i = 0; i < N; i++){
                  if( dp[i] > maxLen){
                      maxLen = dp[i];
                      lastIdx = i;
                  }
              }
              
               vector < int > lis;
              
              for( int i = lastIdx ; i != -1; i = parent[i] )
                       lis.push_back( arr[i]);
              
              reverse(lis.begin(),lis.end());
              
              return lis;
              
    }
};

int main(){
    
    return 0;
}