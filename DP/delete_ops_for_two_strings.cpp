/*

https://leetcode.com/problems/delete-operation-for-two-strings/

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

    // top down solution  
 
class Solution {
public:
   int M , N;
   int dp[505][505];
    int f( string& word1, string& word2, int i, int j){
            if( i == M) return ( N - j);
            if( j == N) return ( M - i);

             
             if( dp[i][j] != -1 ) return dp[i][j];

              int res = 0;
            if( word1[i] == word2[j] ){

              res = 0 + f( word1, word2, i + 1, j + 1 );

            }else{
                res = min( 1+ f( word1, word2, i + 1, j  ), 1+ f( word1, word2, i , j + 1 ) );
            }

            return dp[i][j] =  res;
    }

    // bottom up solution

    int fbu( string s1, string s2 ){
        
        // s1 is empty fill M th row with s2 
            
             vector < vector < int>> tab( M + 1, vector <int >( N+ 1,0));

              // s1 is empty fill M th row with s2 
        for( int  j = N -1; j >= 0; j--)
          tab[M][j] = ( N - j);

        for( int i = M -1 ; i >= 0; i--)
            tab[i][N] =  ( M - i);
        

        for( int i = M -1; i >= 0; i--){
            for( int j = N - 1; j >= 0; j--){
                if( s1[i] == s2[j])
                 tab[i][j] =  tab[i+1][j+1];
                else 
                  tab[i][j] =  min( 1+   tab[i+1][j],  1 + tab[i][j+ 1]);
            }
        }

         return tab[0][0];
    }
    int minDistance(string word1, string word2) {
             M = word1.size(), N = word2.size();
             memset( dp, -1, sizeof( dp));

             int res =  fbu( word1, word2);

             return res;
    }
};

int main() {  setupIO();
     
     
    return 0;
}
