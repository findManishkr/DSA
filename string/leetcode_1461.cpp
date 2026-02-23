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

class Solution {
public:
    bool hasAllCodes(string s, int k) {

        int n = s.size();

        // early pruning
        if( n < k ) return false;
        if(  n - k + 1 < (1 << k)  )      // at least no of substring ie (n -k + 1) >= 2^k
        return false;

        unordered_set< string > seen;

        for( int i = 0; i < ( n -k + 1); i++){
        
           string str = s.substr(i,k);

           seen.insert(str);

        }

        return seen.size() == ( 1 << k);
    }
};


/*

Algorithm\

-If k > s.length, return false
-If n - k + 1 < 2^k, return false
-Iterate from 0 to n-k
-Extract substring of length k
-Insert into set
-If set size becomes 2^k, return true
-End → return false

*/

int main(int argc, char const *argv[]) { setupIO();



    return 0;
}