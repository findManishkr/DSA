#include <bits/stdc++.h>
using namespace std;

void setupIO() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif
}
void longestCommonSubstr(string S1, string S2) {

    int n = S1.length(), m = S2.length();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    int ans = 0;

      
    for( int i = n -1 ; i >= 0 ; i--){
        for( int j = m - 1; j >= 0; j--){
            if( S1[i] == S2[j]){
                dp[i][j] = 1 + dp[i+1][j+1];
                ans = max( dp[i][j], ans);
            }
        }
    }
     
    int maxLen = 0;
    int startIdx = -1;
   
     for( int i = i = 0; i < n; i++){
        for( int j = 0; j < m ; j++){
            if( dp[i][j] > maxLen){
                maxLen = dp[i][j];
                startIdx = i ;     // or you can take j also
            }
        }
     }
   
     
      
        cout << S1.substr( startIdx, maxLen) ;
   
}

int main() {  setupIO();
     string s , t;
     cin >> s;
     cin >> t;

    longestCommonSubstr(s, t);
     
    return 0;
}
