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


// approach : brute force ie recursion + backtracking solution

class Solution {
public:
     bool IsPalindrome( string s){
            int n = s.size();

            int i = 0, j = n -1;
            while( i < j){
                if(s[i] != s[j]) return false;
                i++, j--;
            }

       return true;
     }
     void f( int idx, vector< string> &curr, string &s, int n, vector< vector< string>>&ans){
                  if( idx >= n){
                     ans.push_back( curr);
                     return ;
                  }


             // try all prefixes len

             for( int len = 1; len <= n; len++ ){

                   if( idx + len > n ) continue ;
               
                   string str = s.substr(idx, len);
                   if( !IsPalindrome(str)) continue;
                   curr.push_back(str);
                   
                   f(idx + len, curr, s, n,ans);
                   curr.pop_back();

                   // revert the changes here , ie do the back tracking

             }


     }
    vector<vector<string>> partition(string s) {
                  int n = s.size();
                  vector<vector<string>>ans;
                  vector<string>curr;

                  f(0, curr, s, n,ans );


                  return ans;

    }
};

// add optimized dp solution


int main(int argc, char const *argv[]) { setupIO();



    return 0;
}