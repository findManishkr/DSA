/*

https://leetcode.com/problems/number-of-good-ways-to-split-a-string/

*/


#include <bits/stdc++.h>
using namespace std;

#define loop(i,a,b)     for(int i=(a); i<(b); i++)
#define all(x)          (x).begin(), (x).end()


class Solution {
public:
    int numSplits(string s) {
        
        int n = s.size();

         int res = 0;

        map < char, int > mp1, mp2;

        for( char ch : s) mp2[ch]++;

        for( int i=   0; i < n; i++){
        
         if( mp1.size() == mp2.size() ){
               res++;
         }
         
          if( mp2[s[i]] == 1){
              mp2.erase( s[i]);
          }else{
              mp2[s[i]]--;
          }

          mp1[s[i]]++;

        }

   
        return res;
    }
};

int main(int argc, char const *argv[]) { 



    return 0;
}