/*
https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

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

#define inf 1e9
class Solution {
  public:
     int dp[105][105];
    int f( int i, int j, vector<int>&arr){
          // base case 
          if( i + 1 == j ) return 0;
          
          if( dp[i][j] != -1) return dp[i][j];
          
          int ans = inf;
          
          for( int k = i + 1; k <= j -1; k++){
              ans = min( ans, arr[i]*arr[k]*arr[j] + f(i,k,arr) + f(k,j,arr));
          }
          
          
        
        return dp[i][j] =  ans;
    }
    
    
    int fbu (vector<int> &arr) {
         int N = arr.size();
          vector < vector <int>>tab(N,vector<int>(N,0));
          // as if arr len ie 1 or 2 , tab[] = 0
            
            for( int len = 3; len <= N; len++){
                   
                for( int i = 0; i + len - 1 < N; i++){
                     int j = i + len - 1;
                     tab[i][j] = INT_MAX;
                     for( int k = i + 1; k < j ; k++)
                      tab[i][j] = min( tab[i][j] , tab[i][k] + tab[k][j] + arr[i]* arr[k] * arr[j]);
                }
            }
            return tab[0][N-1];
    }
    int matrixMultiplication(vector<int> &arr) {
             
             memset( dp, -1, sizeof(dp));
        
        return f( 0, arr.size()-1, arr);
    }

int main(int argc, char const *argv[]) { setupIO();



    return 0;
}