/*

https://leetcode.com/problems/construct-k-palindrome-strings/description/


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

class Solution {
public:
    bool canConstruct(string s, int k) {
        

          unordered_map < char, int >fm;

             for( char ch : s)
                 fm[ch]++;

           if( s.size() < k ) return false;

           int oddfreqcnt = 0 ;

           for(  auto it = fm.begin(); it != fm.end(); it++)     
                if( it->second % 2 )oddfreqcnt++;


           
           if(oddfreqcnt > k ) return false;

           return true;
    }


};

/*

 a char  having odd freq , will contribute to a new palindromic string

 if( count( oddfreq) > k )  then there are more than k palindromic string

 if( count( oddfreq == k) )   then ,   answer is true

 if( count (odd) < k)  ans ( s.size() >= k )    even freq char will make ,no of palindroem == k



*/

int main(int argc, char const *argv[]) { setupIO();



    return 0;
}