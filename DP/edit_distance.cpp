#include <bits/stdc++.h>
using namespace std;

void setupIO() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif
}

int dp[ 5005][ 5005];
int f( string &s, string &t, int i, int j){


       if( i == s.size() )  return t.size() - j;    //    this much char to be add to s to make s == t;
       if( j == t.size() ) return s.size() - i;    // this much char to be deleted from to make s == t

         if( dp[i][j] != -1) return dp[i][j];

           int ans = 0;

           if( s[i] == t[j])
            ans = 0 + f( s, t, i + 1, j + 1);
           else {
           ans = 1 + min( { 
                            f( s, t, i + 1, j + 1),   // replace 
                            f( s, t, i , j + 1) ,    // insert 
                            f( s, t, i + 1, j )        // delete

                           })   ;

                        }           
             
      return  dp[i][j] =  ans;
}

int main() {  setupIO();
     string s , t;
     cin >> s;
     cin >> t;

     memset( dp, -1, sizeof( dp));

     cout << f( s, t, 0, 0) <<'\n';
    
    return 0;
}
