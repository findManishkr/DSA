/*

https://leetcode.com/problems/distinct-subsequences/description/?envType=study-plan-v2&envId=dynamic-programming

  concept : pick /notpick , subset counting

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

#define usi unsigned int
class Solution {
public:
    int S, T;
     // top down 
    int dp[1001][1001];
    int f( string &s, string &t, int i, int j){
           // 
           if( i == S && j >= T) return 1;    // a subsequence found
           if( i >= S && j < T) return 0;     // not possible to form subsequence

           if( dp[i][j] != -1) return dp[i][j];
             
             int res = 0;

           if( s[i] == t[j]){
             int skip = f( s, t, i+ 1, j);
             int take = f(s, t, i+1, j+ 1);
             res = skip + take;
           }else{
               res = f( s, t, i+ 1,j);
              
           }


         return dp[i][j] = res;
    }

      // bottom up solution

    int fbu( string s, string t){
          vector < vector < usi >> tab( S+ 1,  vector < usi > ( T+  1, 0));

            for( int i = 0; i <= S; i++)
            tab[i][T] = 1;

            for( int i =  S-1; i >= 0; i-- ){
                for( int j = T- 1; j >= 0; j-- ){
                    if(  s[i] == t[j] )
                    tab[i][j] = tab[i+1][j] + tab[i+1][j+1];
                    else 
                    tab[i][j] = tab[i+1][j];
                }
            }              

         return tab[0][0];
    }
    int numDistinct(string s, string t) {
             S = s.size(), T = t.size();

              memset( dp, -1, sizeof(dp));
            // return f(s,t,0,0);

            return fbu(s,t);
    }
};

int main() {  setupIO();
     
     
    return 0;
}
