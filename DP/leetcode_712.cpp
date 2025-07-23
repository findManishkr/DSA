/*

  https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/?envType=study-plan-v2&envId=dynamic-programming

   concept : lcs or edit distance type patter

*/


#include <bits/stdc++.h>
using namespace std;

void setupIO() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif
}

class Solution {
public:
    int M, N;
    vector<vector<int>> dp;
    int f(string& s1, string& s2, int i, int j) {
        if (i == M) {

            int ans = 0;
            for (int idx = j; idx < N; idx++)
                ans += int(s2[idx]);

            return dp[i][j] = ans;
        }
        if (j == N) {

            int ans = 0;
            for (int idx = i; idx < M; idx++)
                ans += int(s1[idx]);

            return dp[i][j] = ans;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        int res = 0;

        if (s1[i] == s2[j]) {

            res = f(s1, s2, i + 1, j + 1);

        } else {

            res = min(int(s1[i]) + f(s1, s2, i + 1, j),
                      int(s2[j]) + f(s1, s2, i, j + 1));
        }

        return dp[i][j] = res;
    }
    int fbu( string s1, string s2){
        
          vector < vector < int >> tab( M+ 1, vector <int >( N + 1,0));

             // base case if s1 is empty() then fill Mth row 

             for( int j = N -1 ; j >= 0; j--)
             tab[M][j] =  tab[M][ j+ 1] +   int( s2[j]  );

              // base case if s2 is empty() then fill Nth row 
             for( int i = M - 1; i >= 0; i--)
             tab[i][N] = tab[i+1][ N] + int( s1[i]);


             for( int i = M - 1; i >= 0; i--){
                for( int j = N -1 ; j >= 0; j--){
                       if( s1[i] == s2[j]){
                            tab[i][j] =    tab[i+1][j+1];
                       }else{
                      
                         tab[i][j]  =  min(   int(s1[i] ) +    tab[i+ 1][j] ,  int(s2[j])  +    tab[i][j+1] );

                       }

                }
             }
             
             
                return tab[0][0];
    }
    int minimumDeleteSum(string s1, string s2) {
        M = s1.size(), N = s2.size();
        dp.assign(M + 1, vector<int>(N + 1, -1));
             
              int res = fbu(s1, s2);
            
         
         
        return res;
    }
};

int main() {  setupIO();
    
     
    return 0;
}
