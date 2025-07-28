/*

https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

  concept : variable size sliding window
*/

#include <bits/stdc++.h>
using namespace std;

    class Solution {
public:
    int lengthOfLongestSubstring(string s) {
            int N = s.size();
           int res = 0;
           int left = 0;
           unordered_set< int > seen;

           for( int right = 0; right < N; right++ ){

              while( seen.count( s[right]) ){
              
                seen.erase( s[left]);
                left++;


              }
               seen.insert( s[right]);
               res = max( res, right - left + 1);
             
           }


           return res;


    }
};


//  My apporach 

// 1. i keeped two pointers at start of the string left and right ;
// 2. i kept left pointer fixed, and moved right pointer till i encountered unqiue char and updated the maxLen( for this i used a hasset )
// 3. if i encountered duplicate , then i removed all previous characters starting form left  pointer till duplicate removed 
// 4. kept doing this process untill the end of string 


// ` time complexity :`  O( N);
// ` extra space :   O ( maxsizeof( set) ie O( N ) in worst case `

int main(){


    return 0;
}