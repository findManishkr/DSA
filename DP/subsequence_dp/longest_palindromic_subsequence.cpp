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

class Solution1 {
public:
   int dp[1005][1005];
    int f( int i, int j, string &s){
          if( i == j ) return 1;
          if( i > j ) return 0;

          if( dp[i][j] != -1) return dp[i][j];


          int res = 0;
          if( s[i] == s[j])
          res += 2 + f(i+1, j-1, s);
          else
          res = max( f(i+1, j, s), f(i,j-1, s));


          return dp[i][j] =  res;
    }
    int longestPalindromeSubseq(string s) {
        
        int n = s.size();
        memset(dp, -1, sizeof(dp));
        return f(0, n-1, s);
    }
};

int main(int argc, char const *argv[]) { setupIO();



    return 0;
}